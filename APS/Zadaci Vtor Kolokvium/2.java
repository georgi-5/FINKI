import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class MapEntry<K extends Comparable<K>,E> implements Comparable<K> {

    // Each MapEntry object is a pair consisting of a key (a Comparable
    // object) and a value (an arbitrary object).
    K key;
    E value;

    public MapEntry (K key, E val) {
        this.key = key;
        this.value = val;
    }

    public int compareTo (K that) {
        // Compare this map entry to that map entry.
        @SuppressWarnings("unchecked")
        MapEntry<K,E> other = (MapEntry<K,E>) that;
        return this.key.compareTo(other.key);
    }

    public String toString () {
        return "<" + key + "," + value + ">";
    }
}

class SLLNode<E> {
    protected E element;
    protected SLLNode<E> succ;

    public SLLNode(E elem, SLLNode<E> succ) {
        this.element = elem;
        this.succ = succ;
    }

    @Override
    public String toString() {
        return element.toString();
    }
}

class CBHT<K extends Comparable<K>, E> {

    // An object of class CBHT is a closed-bucket hash table, containing
    // entries of class MapEntry.
    private SLLNode<MapEntry<K,E>>[] buckets;

    @SuppressWarnings("unchecked")
    public CBHT(int m) {
        // Construct an empty CBHT with m buckets.
        buckets = (SLLNode<MapEntry<K,E>>[]) new SLLNode[m];
    }

    private int hash(K key) {
        return Math.abs(key.hashCode()) % buckets.length;
    }

    public SLLNode<MapEntry<K,E>> search(K targetKey) {
        // Find which if any node of this CBHT contains an entry whose key is
        // equal
        // to targetKey. Return a link to that node (or null if there is none).
        int b = hash(targetKey);
        for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (targetKey.equals(((MapEntry<K, E>) curr.element).key))
                return curr;
        }
        return null;
    }

    public void insert(K key, E val) {    // Insert the entry <key, val> into this CBHT.
        MapEntry<K, E> newEntry = new MapEntry<K, E>(key, val);
        int b = hash(key);
        for (SLLNode<MapEntry<K,E>> curr = buckets[b]; curr != null; curr = curr.succ) {
            if (key.equals(((MapEntry<K, E>) curr.element).key)) {
                // Make newEntry replace the existing entry ...
                curr.element = newEntry;
                return;
            }
        }
        // Insert newEntry at the front of the 1WLL in bucket b ...
        buckets[b] = new SLLNode<MapEntry<K,E>>(newEntry, buckets[b]);
    }

    public void delete(K key) {
        // Delete the entry (if any) whose key is equal to key from this CBHT.
        int b = hash(key);
        for (SLLNode<MapEntry<K,E>> pred = null, curr = buckets[b]; curr != null; pred = curr, curr = curr.succ) {
            if (key.equals(((MapEntry<K,E>) curr.element).key)) {
                if (pred == null)
                    buckets[b] = curr.succ;
                else
                    pred.succ = curr.succ;
                return;
            }
        }
    }

    public String toString() {
        String temp = "";
        for (int i = 0; i < buckets.length; i++) {
            temp += i + ":";
            for (SLLNode<MapEntry<K,E>> curr = buckets[i]; curr != null; curr = curr.succ) {
                temp += curr.element.toString() + " ";
            }
            temp += "\n";
        }
        return temp;
    }

}

public class KumanovskiDijalekt {
    public static void main (String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        String rechnik[]=new String[N];
        for(int i=0;i<N;i++){
            rechnik[i]=br.readLine();
        }


        String tekst=br.readLine();
        if(N==0){
            System.out.println(tekst);
            return;
        }
        CBHT<String, String> mapa = new CBHT<>(N*N);
        for(int i=0;i<N;i++){
            String one = rechnik[i].split(" ")[0];
            String two = rechnik[i].split(" ")[1];
            mapa.insert(one,two);
        }
        String text[] = tekst.split(" ");
        for(String word : text){
            boolean flag = false;
            if(Character.isUpperCase(word.charAt(0))) flag = true;
            word = word.toLowerCase();
            //zbor
            if(mapa.search(word)!=null){
                if(flag) System.out.print(mapa.search(word).element.value.substring(0,1).toUpperCase()+mapa.search(word).element.value.substring(1)+" ");
                else System.out.print(mapa.search(word).element.value+" ");
            }
            //,zbor
//            else if(mapa.search(word.substring(1))!=null){
//                if(flag) System.out.print(word.charAt(0)+mapa.search(word).element.value.substring(1,2).toUpperCase()+mapa.search(word).element.value.substring(2)+" ");
//                else System.out.print(word.charAt(0)+mapa.search(word.substring(1)).element.value+" ");
//            }
            //zbor,
            else if(mapa.search(word.substring(0,word.length()-1))!=null){
                if(flag) System.out.print(mapa.search(word.substring(0,word.length()-1)).element.value.substring(0,1).toUpperCase()+mapa.search(word.substring(0,word.length()-1)).element.value.substring(1)+word.charAt(word.length()-1)+" ");
                else System.out.print(mapa.search(word.substring(0,word.length()-1)).element.value+word.charAt(word.length()-1)+" ");
            }
            else{
                if(flag) System.out.print(word.substring(0,1).toUpperCase()+word.substring(1)+" ");
                else System.out.print(word+" ");
            }
        }
    }
}