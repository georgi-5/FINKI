#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int const username_length = 100;
int const foldername_length = 255;
int const max_files_folder = 100;


class Image{
protected:
  char * name;
  char author[username_length+1];
  int width;
  int height;

public:
  Image (char* n="untitled", char* un="unknown", int w=800, int h=800) {
    this->name = new char[strlen(n)+1];
    strcpy(this->name, n);
    strncpy(this->author, un, username_length);
    this->author[50] = '\0';
    this->width = w;
    this->height = h;
  }

  virtual ~Image(){
    delete [] this->name;
  }

  Image (const Image & orig){
    this->name = new char[strlen(orig.name)+1];
    strcpy(this->name, orig.name);

    strncpy(this->author, orig.author, username_length);
    this->author[username_length] = '\0';

    this->width = orig.width;
    this->height = orig.height;
  }

  Image& operator=(const Image& rhs){
    if (this!=&rhs){
      delete [] this->name;

      this->name = new char[strlen(rhs.name)+1];
      strcpy(this->name, rhs.name);

      strncpy(this->author, rhs.author, username_length);
      this->author[username_length] = '\0';

      this->width= rhs.width;
      this->height= rhs.height;
    }
    return *this;
  }

  virtual int fileSize() const{
    return this->width * this->height * 3;
  }

  friend ostream& operator<<(ostream& o, const Image& f){
    o << f.name << " " << f.author << " " << f.fileSize() << '\n';
    return o;
  }

  bool operator > (const Image& rhs){
    return this->fileSize() > rhs.fileSize();
  }
};

class TransparentImage: public Image{
protected:
  bool transparency_layers;
public:
  TransparentImage(char* n="untitled", char* un="unknown", int w=800, int h=800, bool tl=true)
      :Image(n, un, w, h) {
    this->transparency_layers = tl;
  }

  TransparentImage(const TransparentImage & orig){
    this->name = new char[strlen(orig.name)+1];
    strcpy(this->name, orig.name);

    strncpy(this->author, orig.author, username_length);
    this->author[username_length] = '\0';

    this->width = orig.width;
    this->height= orig.height;

    this->transparency_layers = orig.transparency_layers;
  }

  TransparentImage& operator=(const TransparentImage& rhs){
    if (this!=&rhs){
      delete [] this->name;

      this->name = new char[strlen(rhs.name)+1];
      strcpy(this->name, rhs.name);

      strncpy(this->author, rhs.author, username_length);
      this->author[username_length] = '\0';

      this->width = rhs.width;
      this->height= rhs.height;

      this->transparency_layers = rhs.transparency_layers;
    }
    return *this;
  }

  int fileSize() const {
    if (transparency_layers)
      return this->width * this->height * 4;
    else {
      return this->width * this->height + (this->width * this->height)/8;
    }
  }

  friend ostream& operator<<(ostream& o, const TransparentImage& f){
    o << f.name << " " << f.author << " " << f.fileSize() << '\n';
    return o;
  }
};

class Folder{
protected:
    char name[foldername_length+1];
    char username[username_length+1];

    Image * files[max_files_folder];
    int num_files;

public:
  Folder(char* n="untitled", char* un="unknown"){
    strncpy(this->name,n,foldername_length);
    this->name[foldername_length] = '\n';

    strncpy(this->username,un,username_length);
    this->name[username_length] = '\n';

    this->num_files = 0;
  }

  Folder(const Folder& orig){
    strcpy(this->name, orig.name);

    strcpy(this->username, orig.username);

    this->num_files = orig.num_files;

    for (int i=0; i<this->num_files; ++i){
      TransparentImage * tf= dynamic_cast<TransparentImage*>(orig.files[i]);

      if (tf){
        this->files[i] = new TransparentImage(*tf);
      }
      else {
        this->files[i] = new Image(*(orig.files[i]));
      }
    }
  }

  ~Folder (){
    for (int i=0; i<this->num_files; ++i){
      delete files[i];
    }
  }


  Folder& operator=(const Folder& rhs){
    if (this!=&rhs){
      strcpy(this->name, rhs.name);

      strcpy(this->username, rhs.username);

      for (int i=0; i<this->num_files; ++i){
        delete files[i];
      }

      this->num_files = rhs.num_files;

      for (int i=0; i<this->num_files; ++i){
        TransparentImage* tf= dynamic_cast<TransparentImage*>(rhs.files[i]);

        if (tf){
            this->files[i] = new TransparentImage(*tf);
        }
        else {
          this->files[i] = new Image(*rhs.files[i]);
        }
      }
    }
    return *this;
  }

  int folderSize() const {
    int s = 0;
    TransparentImage* tf;
    for (int i=0; i<num_files; ++i){
      tf = dynamic_cast<TransparentImage*>(this->files[i]);
      if (tf){
        s+=tf->fileSize();
      }
      else
        s += files[i]->fileSize();
    }
    return s;
  }

  Folder& operator+=(Image &nf){

    if (this->num_files < 255){

      TransparentImage* tf= dynamic_cast<TransparentImage*>(&nf);

      if (tf){
          this->files[num_files] = new TransparentImage(*tf);
      }
      else {
        this->files[num_files] = new Image(nf);
      }

      num_files++;
    }

    return *this;
  }

  Image* operator[](int i){
    if (i<0&&i >= this->num_files)
      return NULL;

    return this->files[i];
  }

  friend ostream& operator<<(ostream & o, Folder& f){
    o << f.name << " " << f.username <<"\n--\n";

    TransparentImage * tf;
    for (int i=0; i<f.num_files; ++i){

      tf = dynamic_cast<TransparentImage*>(f.files[i]);
      if (tf){
          o << *tf;
      }
       else {
        o << *f.files[i];
      }
    }
    o << "--\nFolder size: " << f.folderSize() << endl;
    return o;
  }

  Image* getMaxFile(){
    int mfs = 0;
    int mi = -1;
    int cfs;
    if (num_files>0){
      mfs = this->files[0]->fileSize();
      mi = 0;
      for (int i=0; i<this->num_files; ++i){
        cfs = this->files[i]->fileSize();
        if (cfs > mfs){
          mfs = cfs;
          mi = i;
        }
      }
      return files[mi];
    }
    else return NULL;
  }
};

Folder& max_folder_size(Folder * f, int nf){
    int ms=f[0].folderSize();
    int mi = 0;

    for (int i=0; i<nf; ++i){
      if (f[i].folderSize()>ms){
        mi=i;
        ms=f[i].folderSize();
      }
    }

    return f[mi];
}



int main() {

    int tc; // Test Case

    char name[255];
    char user_name[51];
    int w, h;
    bool tl;

    cin >> tc;

    if (tc==1){
      // Testing constructor(s) & operator << for class File

      cin >> name;
      cin >> user_name;
      cin >> w;
      cin >> h;


      Image f1;

      cout<< f1;

      Image f2(name);
      cout<< f2;

      Image f3(name, user_name);
      cout<< f3;

      Image f4(name, user_name, w, h);
      cout<< f4;
    }
    else if (tc==2){
      // Testing constructor(s) & operator << for class TextFile
      cin >> name;
      cin >> user_name;
      cin >> w >> h;
      cin >> tl;

      TransparentImage tf1;
      cout<< tf1;

      TransparentImage tf4(name, user_name, w, h, tl);
      cout<< tf4;
    }
    else if (tc==3){
      // Testing constructor(s) & operator << for class Folder
      cin >> name;
      cin >> user_name;

      Folder f3(name, user_name);
      cout<< f3;
    }
    else if (tc==4){
      // Adding files to folder
      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image * f;
      TransparentImage *tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<<dir;
    }
    else if(tc==5){
      // Testing getMaxFile for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }
      cout<< *(dir.getMaxFile());
    }
    else if(tc==6){
      // Testing operator [] for folder

      cin >> name;
      cin >> user_name;

      Folder dir(name, user_name);

      Image* f;
      TransparentImage* tf;

      int sub, fileType;

      while (1){
        cin >> sub; // Should we add subfiles to this folder
        if (!sub) break;

        cin >>fileType;
        if (fileType == 1){ // Reading File
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          f = new Image(name,user_name, w, h);
            dir += *f;
        }
        else if (fileType == 2){
          cin >> name;
          cin >> user_name;
          cin >> w >> h;
          cin >> tl;
          tf = new TransparentImage(name,user_name, w, h, tl);
            dir += *tf;
        }
      }

      cin >> sub; // Reading index of specific file
      cout<< *dir[sub];
    }
    else if(tc==7){
      // Testing function max_folder_size
      int folders_num;

      Folder dir_list[10];

      Folder dir;
      cin >> folders_num;

      for (int i=0; i<folders_num; ++i){
        cin >> name;
        cin >> user_name;
        dir = Folder(name, user_name);


        Image* f;
        TransparentImage *tf;

        int sub, fileType;

        while (1){
          cin >> sub; // Should we add subfiles to this folder
          if (!sub) break;

          cin >>fileType;
          if (fileType == 1){ // Reading File
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            f = new Image(name,user_name, w, h);
              dir += *f;
          }
          else if (fileType == 2){
            cin >> name;
            cin >> user_name;
            cin >> w >> h;
            cin >> tl;
            tf = new TransparentImage(name,user_name, w, h, tl);
              dir += *tf;
          }
        }
        dir_list[i] = dir;
      }

      cout<<max_folder_size(dir_list, folders_num);
    }
    return 0;
};