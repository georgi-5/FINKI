import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.NoSuchElementException;
@SuppressWarnings("unchecked")
class BNode<E> {

    public E info;
    public BNode<E> left;
    public BNode<E> right;

    static int LEFT = 1;
    static int RIGHT = 2;

    public BNode(E info) {
        this.info = info;
        left = null;
        right = null;
    }

    public BNode() {
        this.info = null;
        left = null;
        right = null;
    }

    public BNode(E info, BNode<E> left, BNode<E> right) {
        this.info = info;
        this.left = left;
        this.right = right;
    }

    @Override
    public String toString() {
        return ""+info;
    }
}
@SuppressWarnings("unchecked")
class BTree<E> {

    public BNode<E> root;

    public BTree() {
        root = null;
    }

    public BTree(E info) {
        root = new BNode<E>(info);
    }

    public void makeRoot(E elem) {
        root = new BNode(elem);
    }

    public void makeRootNode(BNode<E> node) {
        root = node;
    }

    public BNode<E> addChild(BNode<E> node, int where, E elem) {

        BNode<E> tmp = new BNode<E>(elem);

        if (where == BNode.LEFT) {
            if (node.left != null)  // veke postoi element
                return null;
            node.left = tmp;
        } else {
            if (node.right != null) // veke postoi element
                return null;
            node.right = tmp;
        }

        return tmp;
    }

    public BNode<E> addChildNode(BNode<E> node, int where, BNode<E> tmp) {

        if (where == BNode.LEFT) {
            if (node.left != null)  // veke postoi element
                return null;
            node.left = tmp;
        } else {
            if (node.right != null) // veke postoi element
                return null;
            node.right = tmp;
        }

        return tmp;
    }

    public BNode<E> inorder(BNode <E> root){
        if(root==null){
            return null;
        }
        inorder(root.left);
        System.out.println(root.info);
        inorder(root.right);

        return null;
    }

    public BNode<E> find(BNode<E> node,String val){
        if(node==null){
            return null;
        }
        if(node.info.equals(val)){
            return node;
        }
        BNode<E> left=find(node.left,val);
        if(left!=null){
            return left;
        }
        BNode<E> right=find(node.right,val);
        if(right!=null){
            return right;
        }
        return null;
    }

    public int findDepth(BNode<E> node,BNode<E> node1){
        if(node==null){
            return -1;
        }
        if(node==node1){
            return 0;
        }
        int leftDepth=findDepth(node.left,node1);
        if(leftDepth!=-1){
            return leftDepth+1;
        }
        int rightDepth=findDepth(node.right,node1);
        if(rightDepth!=-1){
            return rightDepth+1;
        }
        return -1;
    }
    public BNode<E> lca(BNode<E> root,BNode<E> n1,BNode<E> n2){
        if(root==null){
            return null;
        }
        if(root==n1 || root==n2){
            return root;
        }

        BNode<E> left=lca(root.left,n1,n2);
        BNode<E> right=lca(root.right,n1,n2);

        if(left!=null && right!=null){
            return root;
        }
        return (left!=null)?left:right;
    }
    public int findIt(BNode<E> root,BNode<E> n1,BNode<E> n2){
        BNode<E> lca=lca(root,n1,n2);
        int d1,d2;
        d1=findDepth(lca,n1);
        d2=findDepth(lca,n2);

        return d1+d2;
    }

}


@SuppressWarnings("unchecked")
interface Stack<E> {

    // Elementi na stekot se objekti od proizvolen tip.

    // Metodi za pristap:

    public boolean isEmpty ();
    // Vrakja true ako i samo ako stekot e prazen.

    public E peek ();
    // Go vrakja elementot na vrvot od stekot.

    // Metodi za transformacija:

    public void clear ();
    // Go prazni stekot.

    public void push (E x);
    // Go dodava x na vrvot na stekot.

    public E pop ();
    // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
}
@SuppressWarnings("unchecked")
class ArrayStack<E> implements Stack<E> {
    private E[] elems;
    private int depth;

    @SuppressWarnings("unchecked")
    public ArrayStack (int maxDepth) {
        // Konstrukcija na nov, prazen stek.
        elems = (E[]) new Object[maxDepth];
        depth = 0;
    }


    public boolean isEmpty () {
        // Vrakja true ako i samo ako stekot e prazen.
        return (depth == 0);
    }


    public E peek () {
        // Go vrakja elementot na vrvot od stekot.
        if (depth == 0)
            throw new NoSuchElementException();
        return elems[depth-1];
    }


    public void clear () {
        // Go prazni stekot.
        for (int i = 0; i < depth; i++)  elems[i] = null;
        depth = 0;
    }


    public void push (E x) {
        // Go dodava x na vrvot na stekot.
        elems[depth++] = x;
    }


    public E pop () {
        // Go otstranuva i vrakja elementot shto e na vrvot na stekot.
        if (depth == 0)
            throw new NoSuchElementException();
        E topmost = elems[--depth];
        elems[depth] = null;
        return topmost;
    }
}
@SuppressWarnings("unchecked")
public class NodeDistance {

    public static void main(String[] args) throws Exception {
        int i, j, k;
        int index;
        String action;

        String line;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        BNode<String> nodes[] = new BNode[N];
        BTree<String> tree = new BTree<String>();

        for (i=0;i<N;i++)
            nodes[i] = new BNode<String>();

        for (i = 0; i < N; i++) {
            line = br.readLine();
            st = new StringTokenizer(line);
            index = Integer.parseInt(st.nextToken());
            nodes[index].info = st.nextToken();
            action = st.nextToken();
            if (action.equals("LEFT")) {
                tree.addChildNode(nodes[Integer.parseInt(st.nextToken())], BNode.LEFT, nodes[index]);
            } else if (action.equals("RIGHT")) {
                tree.addChildNode(nodes[Integer.parseInt(st.nextToken())], BNode.RIGHT, nodes[index]);
            } else {
                // this node is the root
                tree.makeRootNode(nodes[index]);
            }
        }


        int cases = Integer.parseInt(br.readLine());
        for (int l = 0; l < cases; l++) {
            BNode<String> root=tree.root;
            String split[] = br.readLine().split(" +");
            String from = split[0];
            String to = split[1];
            BNode<String> from1=tree.find(root,from);
            BNode<String> to1=tree.find(root,to);
            if(tree.findDepth(root,to1)==-1){
                System.out.println("ERROR");
            }
            else{
            System.out.println(tree.findIt(root,from1,to1)*2);
            }
            // Vasiot kod ovde



        }


        br.close();


    }

}
