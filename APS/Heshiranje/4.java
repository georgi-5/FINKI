import java.util.*;
class Person{
    String name;
    String surname;
    int salary;
    String ip;
    String time;
    String city;
    int spent;

    Person(){
        name="";
        salary=0;
        surname="";
        ip="";
        time="9999:9999";
        city="";
        spent=0;
    }

    public Person(String name, String surname, int salary, String ip, String time, String city, int spent) {
        this.name = name;
        this.surname = surname;
        this.salary = salary;
        this.ip = ip;
        this.time = time;
        this.city = city;
        this.spent = spent;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getSalary() {
        return salary;
    }

    public String getIp() {
        return ip;
    }

    public String getTime() {
        return time;
    }

    public String getCity() {
        return city;
    }
    public int getMax(){
        String time=getTime();
        String []parts=time.split(":");
        String first=parts[0];
        String last=parts[1];
        String finalT=first+last;
        return Integer.parseInt(finalT);
    }
    public int getSpent() {
        return spent;
    }
}
class prog{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=Integer.parseInt(sc.nextLine());
        Map<String,List<Person>> map = new HashMap<>();
        for(int i=0;i<n;i++){
            String []input=sc.nextLine().split("\\s+");
            String name=input[0];
            String surname=input[1];
            int salary=Integer.parseInt(input[2]);
            String ip=input[3];
            String time=input[4];
            String city=input[5];
            int spent=Integer.parseInt(input[6]);
            String []parts=time.split(":");
            String first=parts[0];
            String last=parts[1];
            String finalT=first+last;
            String []parts2=ip.split("\\.");
            String first2=parts2[0];
            String secc=parts2[1];
            String third=parts2[2];
            String finalT2=first2 + "." + secc + "." + third;
            int timez=Integer.parseInt(finalT);
            if(timez>=1159) {
                Person person = new Person(name, surname, salary, ip, time, city, spent);
                map.computeIfAbsent(finalT2, k -> new ArrayList<>()).add(person);
            }
        }
        sc.nextLine();
        int m=Integer.parseInt(sc.nextLine());
        String []list=new String[m];
        for(int i=0;i<m;i++){
            String []input=sc.nextLine().split("\\s+");
            String ip=input[3];
            String []parts=ip.split("\\.");
            String first=parts[0];
            String secc=parts[1];
            String third=parts[2];
            String finalT=first + "." + secc + "." + third;
            list[i]=finalT;
        }
        for(int i=0;i< list.length;i++){
            System.out.println("IP network: "+list[i]+" has the following number of users:");
            System.out.println(map.get(list[i]).size());
            System.out.println("The user who logged on earliest after noon from that network is:");
            Person max=new Person();
            for(int j=0;j<map.get(list[i]).size();j++){
                if(map.get(list[i]).get(j).getMax()<max.getMax()){
                    max=map.get(list[i]).get(j);
                }
            }
            System.out.println(max.getName()+" "+max.getSurname()+" with salary "+max.getSalary()+" from address "+max.getIp()+" who logged in at "+max.getTime());
            System.out.println();
        }
    }
}