import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.NoSuchElementException;
import java.util.*;
//class BNode<E> {
//
//    public E info;
//    public BNode<E> left;
//    public BNode<E> right;
//
//    static int LEFT = 1;
//    static int RIGHT = 2;
//
//    public BNode(E info) {
//        this.info = info;
//        left = null;
//        right = null;
//    }
//
//    public BNode() {
//        this.info = null;
//        left = null;
//        right = null;
//    }
//
//    public BNode(E info, BNode<E> left, BNode<E> right) {
//        this.info = info;
//        this.left = left;
//        this.right = right;
//    }
//
//    @Override
//    public String toString() {
//        return ""+info;
//    }
//}
//class BTree<E> {
//
//    public BNode<E> root;
//
//    public BTree() {
//        root = null;
//    }
//
//    public BTree(E info) {
//        root = new BNode<E>(info);
//    }
//
//    public void makeRoot(E elem) {
//        root = new BNode(elem);
//    }
//
//    public void makeRootNode(BNode<E> node) {
//        root = node;
//    }
//
//    public BNode<E> addChild(BNode<E> node, int where, E elem) {
//
//        BNode<E> tmp = new BNode<E>(elem);
//
//        if (where == BNode.LEFT) {
//            if (node.left != null)  // veke postoi element
//                return null;
//            node.left = tmp;
//        } else {
//            if (node.right != null) // veke postoi element
//                return null;
//            node.right = tmp;
//        }
//
//        return tmp;
//    }
//    public BNode<String> find(BNode<String> node,String val) {
//        if(node == null)
//        {
//            return null;
//        }
//        if(node.info.equals(val)){
//            return node;
//        }
//        BNode<String> tmp = find(node.left,val);
//        if(tmp!=null){
//            return tmp;
//        }
//        BNode<String> tmp2 = find(node.right,val);
//        if(tmp2!=null){
//            return tmp2;
//        }
//        return null;
//    }
//    int depthR(BNode<E> node) {
//        if (node == null)
//            return 0;
//        if ((node.left == null)&&(node.right == null))
//            return 0;
//        return (1 + Math.max(depthR(node.left), depthR(node.right)));
//    }
//    public BNode<E> addChildNode(BNode<E> node, int where, BNode<E> tmp) {
//
//        if (where == BNode.LEFT) {
//            if (node.left != null)  // veke postoi element
//                return null;
//            node.left = tmp;
//        } else {
//            if (node.right != null) // veke postoi element
//                return null;
//            node.right = tmp;
//        }
//
//        return tmp;
//    }
//
//}
//interface Stack<E> {
//
//    // Elementi na stekot se objekti od proizvolen tip.
//
//    // Metodi za pristap:
//
//    public boolean isEmpty ();
//    // Vrakja true ako i samo ako stekot e prazen.
//
//    public E peek ();
//    // Go vrakja elementot na vrvot od stekot.
//
//    // Metodi za transformacija:
//
//    public void clear ();
//    // Go prazni stekot.
//
//    public void push (E x);
//    // Go dodava x na vrvot na stekot.
//
//    public E pop ();
//    // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
//}
//class ArrayStack<E> implements Stack<E> {
//    private E[] elems;
//    private int depth;
//
//    @SuppressWarnings("unchecked")
//    public ArrayStack (int maxDepth) {
//        // Konstrukcija na nov, prazen stek.
//        elems = (E[]) new Object[maxDepth];
//        depth = 0;
//    }
//
//
//    public boolean isEmpty () {
//        // Vrakja true ako i samo ako stekot e prazen.
//        return (depth == 0);
//    }
//
//
//    public E peek () {
//        // Go vrakja elementot na vrvot od stekot.
//        if (depth == 0)
//            throw new NoSuchElementException();
//        return elems[depth-1];
//    }
//
//
//    public void clear () {
//        // Go prazni stekot.
//        for (int i = 0; i < depth; i++)  elems[i] = null;
//        depth = 0;
//    }
//
//
//    public void push (E x) {
//        // Go dodava x na vrvot na stekot.
//        elems[depth++] = x;
//    }
//
//
//    public E pop () {
//        // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
//        if (depth == 0)
//            throw new NoSuchElementException();
//        E topmost = elems[--depth];
//        elems[depth] = null;
//        return topmost;
//    }
//}
//class CBHT<K extends Comparable<K>, E> {
//
//    // An object of class CBHT is a closed-bucket hash table, containing
//    // entries of class MapEntry.
//    private SLLNode<MapEntry<K, E>>[] buckets;
//
//    @SuppressWarnings("unchecked")
//    public CBHT(int m) {
//        // Construct an empty CBHT with m buckets.
//        buckets = (SLLNode<MapEntry<K, E>>[]) new SLLNode[m];
//    }
//
//    private int hash(K key) {
//        // Translate key to an index of the array buckets.
//        return Math.abs(key.hashCode()) % buckets.length;
//    }
//
//    public SLLNode<MapEntry<K, E>> search(K targetKey) {
//        // Find which if any node of this CBHT contains an entry whose key is equal to targetKey.
//        // Return a link to that node (or null if there is none).
//        int b = hash(targetKey);
//        SLLNode<MapEntry<K, E>> currNode = buckets[b];
//        while (currNode != null) {
//            MapEntry<K, E> currEntry = currNode.element;
//            if (currEntry.key.equals(targetKey)) return currNode;
//            else currNode = currNode.succ;
//        }
//        return null;
//    }
//
//    public void insert(K key, E val) {
//        // Insert the entry <key, val> into this CBHT.
//        // If entry with same key exists, overwrite it.
//        MapEntry<K, E> newEntry = new MapEntry<>(key, val);
//        int b = hash(key);
//        SLLNode<MapEntry<K, E>> currNode = buckets[b];
//        while (currNode != null) {
//            MapEntry<K, E> currEntry = currNode.element;
//            if (currEntry.key.equals(key)) {
//                // Make newEntry replace the existing entry ...
//                currNode.element = newEntry;
//                return;
//            } else currNode = currNode.succ;
//        }
//        // Insert newEntry at the front of the SLL in bucket b ...
//        buckets[b] = new SLLNode<>(newEntry, buckets[b]);
//    }
//
//    public void delete(K key) {
//        // Delete the entry (if any) whose key is equal to key from this CBHT.
//        int b = hash(key);
//        SLLNode<MapEntry<K, E>> predNode = null, currNode = buckets[b];
//        while (currNode != null) {
//            MapEntry<K, E> currEntry = currNode.element;
//            if (currEntry.key.equals(key)) {
//                if (predNode == null) buckets[b] = currNode.succ;
//                else predNode.succ = currNode.succ;
//                return;
//            } else {
//                predNode = currNode;
//                currNode = currNode.succ;
//            }
//        }
//    }
//
//    public String toString() {
//        String temp = "";
//        for (int i = 0; i < buckets.length; i++) {
//            temp += i + ":";
//            SLLNode<MapEntry<K, E>> curr = buckets[i];
//            while (curr != null) {
//                temp += curr.element.toString() + " ";
//                curr = curr.succ;
//            }
//            temp += "\n";
//        }
//        return temp;
//    }
//}
//class OBHT<K extends Comparable<K>, E> {
//
//    // An object of class OBHT is an open-bucket hash table, containing entries
//    // of class MapEntry.
//    private MapEntry<K, E>[] buckets;
//
//    // buckets[b] is null if bucket b has never been occupied.
//    // buckets[b] is former if bucket b is formerly-occupied
//    // by an entry that has since been deleted (and not yet replaced).
//
//    static final int NONE = -1; // ... distinct from any bucket index.
//
//    @SuppressWarnings({"rawtypes", "unchecked"})
//    private static final MapEntry former = new MapEntry(null, null);
//    // This guarantees that, for any genuine entry e,
//    // e.key.equals(former.key) returns false.
//
//    private int occupancy = 0;
//    // ... number of occupied or formerly-occupied buckets in this OBHT.
//
//    @SuppressWarnings("unchecked")
//    public OBHT(int m) {
//        // Construct an empty OBHT with m buckets.
//        buckets = (MapEntry<K, E>[]) new MapEntry[m];
//    }
//
//
//    private int hash(K key) {
//        // Translate key to an index of the array buckets.
//        return Math.abs(key.hashCode()) % buckets.length;
//    }
//
//
//    public int search(K targetKey) {
//        // Find which if any bucket of this OBHT is occupied by an entry whose key
//        // is equal to targetKey. Return the index of that bucket.
//        int b = hash(targetKey);
//
//        for (int n_search = 0; n_search < buckets.length; n_search++) {
//            MapEntry<K, E> currEntry = buckets[b];
//            if (currEntry == null) return NONE;
//            else if (currEntry.key.equals(targetKey)) return b;
//            else b = (b + 1) % buckets.length;
//        }
//        return NONE;
//    }
//
//    public MapEntry<K, E> getBucket(int bucket) {
//        return buckets[bucket];
//    }
//
//
//    public void insert(K key, E val) {
//        // Insert the entry <key, val> into this OBHT.
//        MapEntry<K, E> newEntry = new MapEntry<K, E>(key, val);
//        int b = hash(key);
//        int n_search = 0;
//        Integer free_position = null;
//        Integer existing_position = null;
//        while (n_search < buckets.length) {
//            MapEntry<K, E> currEntry = buckets[b];
//            if (currEntry == null) {
//                if (free_position == null) free_position = b;
//                break;
//            } else if (key.equals(currEntry.key)) {
//                existing_position = b;
//                break;
//            } else {
//                if (currEntry == former && free_position == null) {
//                    free_position = b;
//                }
//                b = (b + 1) % buckets.length;
//                n_search++;
//            }
//        }
//        if (existing_position != null)
//            buckets[existing_position] = newEntry;
//        else if (free_position != null) {
//            buckets[free_position] = newEntry;
//            if (++occupancy == buckets.length) {
//                System.out.println("Hash tabelata e polna!!!");
//            }
//        } else {
//            // failed to insert, table was already full
//        }
//    }
//
//
//    @SuppressWarnings("unchecked")
//    public void delete(K key) {
//        // Delete the entry (if any) whose key is equal to key from this OBHT.
//        int b = hash(key);
//        int n_search = 0;
//        while (n_search < buckets.length) {
//            MapEntry<K, E> currEntry = buckets[b];
//            if (currEntry == null) return;
//            else if (currEntry.key.equals(key)) {
//                buckets[b] = former;
//                return;
//            } else {
//                b = (b + 1) % buckets.length;
//                n_search++;
//            }
//        }
//    }
//
//
//    public String toString() {
//        String temp = "";
//        for (int i = 0; i < buckets.length; i++) {
//            temp += i + ":";
//            if (buckets[i] == null)
//                temp += "\n";
//            else if (buckets[i] == former)
//                temp += "former\n";
//            else
//                temp += buckets[i] + "\n";
//        }
//        return temp;
//    }
//
//
//    public OBHT<K, E> clone() {
//        OBHT<K, E> copy = new OBHT<K, E>(buckets.length);
//        for (int i = 0; i < buckets.length; i++) {
//            MapEntry<K, E> e = buckets[i];
//            if (e != null && e != former)
//                copy.buckets[i] = new MapEntry<K, E>(e.key, e.value);
//            else
//                copy.buckets[i] = e;
//        }
//        return copy;
//    }
//}
//class MapEntry<K extends Comparable<K>, E> {
//    // Each MapEntry object is a pair consisting of a key (a Comparable object)
//    // and a value (an arbitrary object).
//    K key;
//    E value;
//
//    public MapEntry(K key, E val) {
//        this.key = key;
//        this.value = val;
//    }
//
//    public String toString() {
//        return "<" + key + "," + value + ">";
//    }
//}
class SLL<E> {
    private SLLNode<E> first;

    public SLL() {
        // Construct an empty SLL
        this.first = null;
    }

    public void deleteList() {
        first = null;
    }

    public int size() {
        int listSize = 0;
        SLLNode<E> tmp = first;
        while(tmp != null) {
            listSize++;
            tmp = tmp.succ;
        }
        return listSize;
    }

    @Override
    public String toString() {
        String ret = new String();
        if (first != null) {
            SLLNode<E> tmp = first;
            ret += tmp.element;
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret += "->" + tmp.element;
            }
        } else
            ret = "Prazna lista!!!";
        return ret;
    }

    public void insertFirst(E o) {
        SLLNode<E> ins = new SLLNode<E>(o, null);
        ins.succ = first;
        //SLLNode<E> ins = new SLLNode<E>(o, first);
        first = ins;
    }

    public void insertAfter(E o, SLLNode<E> node) {
        if (node != null) {
            SLLNode<E> ins = new SLLNode<E>(o, node.succ);
            node.succ = ins;
        } else {
            System.out.println("Dadenot jazol e null");
        }
    }
    public void insertBefore(E o, SLLNode<E> before) {

        if (first != null) {
            SLLNode<E> tmp = first;
            if(first==before){
                this.insertFirst(o);
                return;
            }
            //ako first!=before
            while (tmp.succ != before && tmp.succ!=null)
                tmp = tmp.succ;
            if (tmp.succ == before) {
                tmp.succ = new SLLNode<E>(o, before);;
            } else {
                System.out.println("Elementot ne postoi vo listata");
            }
        } else {
            System.out.println("Listata e prazna");
        }
    }

    public void insertLast(E o) {
        if (first != null) {
            SLLNode<E> tmp = first;
            while (tmp.succ != null)
                tmp = tmp.succ;
            tmp.succ = new SLLNode<E>(o, null);
        } else {
            insertFirst(o);
        }
    }

    public E deleteFirst() {
        if (first != null) {
            SLLNode<E> tmp = first;
            first = first.succ;
            return tmp.element;
        } else {
            System.out.println("Listata e prazna");
            return null;
        }
    }

    public E delete(SLLNode<E> node) {
        if (first != null) {
            SLLNode<E> tmp = first;
            if(first == node) {
                return this.deleteFirst();
            }
            while (tmp.succ != node && tmp.succ.succ != null)
                tmp = tmp.succ;
            if (tmp.succ == node) {
                tmp.succ = tmp.succ.succ;
                return node.element;
            } else {
                System.out.println("Elementot ne postoi vo listata");
                return null;
            }
        } else {
            System.out.println("Listata e prazna");
            return null;
        }

    }

    public SLLNode<E> getFirst() {
        return first;
    }

    public SLLNode<E> find(E o) {
        if (first != null) {
            SLLNode<E> tmp = first;
            while (!tmp.element.equals(o) && tmp.succ != null)
                tmp = tmp.succ;
            if (tmp.element.equals(o)) {
                return tmp;
            } else {
                System.out.println("Elementot ne postoi vo listata");
            }
        } else {
            System.out.println("Listata e prazna");
        }
        return null;
    }

    public void merge (SLL<E> in){
        if (first != null) {
            SLLNode<E> tmp = first;
            while(tmp.succ != null)
                tmp = tmp.succ;
            tmp.succ = in.getFirst();
        }
        else{
            first = in.getFirst();
        }
    }

    public void mirror() {
        if (first != null) {
            //m=nextsucc, p=tmp,q=next
            SLLNode<E> tmp = first;
            SLLNode<E> newsucc = null;
            SLLNode<E> next;

            while(tmp != null){
                next = tmp.succ;
                tmp.succ = newsucc;
                newsucc = tmp;
                tmp = next;
            }
            first = newsucc;
        }
    }
}
class SLLNode<E> {
    protected E element;
    protected SLLNode<E> succ;

    public SLLNode(E elem, SLLNode<E> succ) {
        this.element = elem;
        this.succ = succ;
    }
}
class DLLNode<E> {
    protected E element;
    protected DLLNode<E> pred, succ;
    public DLLNode(E elem, DLLNode<E> pred, DLLNode<E> succ) {
        this.element = elem;
        this.pred = pred;
        this.succ = succ;
    }

    @Override
    public String toString() {
        return element.toString();
    }
}
class DLL<E> {
    private DLLNode<E> first, last;

    public DLL() {
        // Construct an empty SLL
        this.first = null;
        this.last = null;
    }

    public void insertFirst(E o) {
        DLLNode<E> ins = new DLLNode<E>(o, null, first);
        if (first == null)
            last = ins;
        else
            first.pred = ins;
        first = ins;
    }

    public void insertLast(E o) {
        if (first == null)
            insertFirst(o);
        else {
            DLLNode<E> ins = new DLLNode<E>(o, last, null);
            last.succ = ins;
            last = ins;
        }
    }

    public void insertAfter(E o, DLLNode<E> after) {
        if (after == last) {
            insertLast(o);
            return;
        }
        DLLNode<E> ins = new DLLNode<E>(o, after, after.succ);
        after.succ.pred = ins;
        after.succ = ins;
    }

    public void insertBefore(E o, DLLNode<E> before) {
        if (before == first) {
            insertFirst(o);
            return;
        }
        DLLNode<E> ins = new DLLNode<E>(o, before.pred, before);
        before.pred.succ = ins;
        before.pred = ins;
    }

    public E deleteFirst() {
        if (first != null) {
            DLLNode<E> tmp = first;
            first = first.succ;
            if (first != null) first.pred = null;
            if (first == null)
                last = null;
            return tmp.element;
        } else
            return null;
    }

    public E deleteLast() {
        if (first != null) {
            if (first.succ == null)
                return deleteFirst();
            else {
                DLLNode<E> tmp = last;
                last = last.pred;
                last.succ = null;
                return tmp.element;
            }
        } else
            return null;
    }

    public E delete(DLLNode<E> node) {
        if (node == first) {
            return deleteFirst();
        }
        if (node == last) {
            return deleteLast();
        }
        node.pred.succ = node.succ;
        node.succ.pred = node.pred;
        return node.element;

    }

    public DLLNode<E> find(E o) {
        if (first != null) {
            DLLNode<E> tmp = first;
            while (!tmp.element.equals(o) && tmp.succ != null)
                tmp = tmp.succ;
            if (tmp.element.equals(o)) {
                return tmp;
            } else {
                System.out.println("Elementot ne postoi vo listata");
            }
        } else {
            System.out.println("Listata e prazna");
        }
        return null;
    }

    public void deleteList() {
        first = null;
        last = null;
    }

    public int getSize() {
        int listSize = 0;
        DLLNode<E> tmp = first;
        while(tmp != null) {
            listSize++;
            tmp = tmp.succ;
        }
        return listSize;
    }

    @Override
    public String toString() {
        String ret = new String();
        if (first != null) {
            DLLNode<E> tmp = first;
            ret += tmp.toString();
            while (tmp.succ != null) {
                tmp = tmp.succ;
                ret += "<->" + tmp.toString();
            }
        } else
            ret = "Prazna lista!!!";
        return ret;
    }

    public String toStringR() {
        String ret = new String();
        if (last != null) {
            DLLNode<E> tmp = last;
            ret += tmp.toString();
            while (tmp.pred != null) {
                tmp = tmp.pred;
                ret += "<->" + tmp.toString();
            }
        } else
            ret = "Prazna lista!!!";
        return ret;
    }

    public DLLNode<E> getFirst() {
        return first;
    }

    public DLLNode<E> getLast() {

        return last;
    }

    public void mirror() {

        DLLNode<E> tmp = null;
        DLLNode<E> current = first;
        last = first;
        while(current!=null) {
            tmp = current.pred;
            current.pred = current.succ;
            current.succ = tmp;
            current = current.pred;
        }

        if(tmp!=null && tmp.pred!=null) {
            first=tmp.pred;
        }
    }
}


public class NodeDistance {

    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        DLL<Integer> list=new DLL<>();
        for(int i=0; i<n; i++){
            list.insertLast(sc.nextInt());
        }
        int m=sc.nextInt();
        DLLNode<Integer> first=list.getFirst();
        DLLNode<Integer> last=list.getLast();
        System.out.println(list);
        first.pred=last;
        last.succ=first;
        int f=n-m;
        for(int i=0; i<f; i++){
            first=first.succ;
        }
        DLL<Integer> list2=new DLL<>();
        for(int i=0; i<n; i++){
            list2.insertLast(first.element);
            first=first.succ;
        }
        System.out.println(list2);

    }

}
