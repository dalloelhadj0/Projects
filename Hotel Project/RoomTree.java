/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
RoomTree clas
*/
public class RoomTree  {
    private RoomTreeNode overallRoot;

  // default constructor of the RoomTree
    public RoomTree() {
        overallRoot = null;
    }

    // pre : tree is a binary search tree
    // post: value is added to overall tree so as to preserve the binary search
    //       tree property
    public void add(Room value) {
        overallRoot = add(overallRoot, value);
    }

    // post: value is added to given binary search tree so as to preserve the
    //       binary search tree property
    // using the cost as the criteria for building the tree
    private RoomTreeNode add(RoomTreeNode root, Room data) {
        if (root == null) {
            root = new RoomTreeNode(data);
        } else if (data.getCost() < root.data.getCost()) {
            root.left = add(root.left, data);
        } else {
            root.right = add(root.right, data);
        }
        return root;
    }

// return the current number of room available in the hotel 
//to show how much the hotel is growing
  public int countNodes() {
        return countNodes(overallRoot);
    }


// this method helps us count the number of rooms inside our hotel
  private int countNodes(RoomTreeNode node) {
        if(node == null){
            return 0;
        } else if(node.left == null && node.right == null){
            return 1;
            } else{
        //int count = countNodes(node.right);
            return countNodes(node.left) + countNodes(node.right) +1;
     //   if(node.left != null){
       //     count += 1 + countNodes(node.left);
        }   
      //  return count;
    }

    public boolean contains(Room value){
        return contains(overallRoot, value);
    }

   // whether or not a two room are the same based on the criteria of their price
    private boolean contains(RoomTreeNode root, Room data){
        if(root == null){
            return true;
        }else if( data.getCost() == root.data.getCost()){
            return true;
        }else if(data.getCost() < root.data.getCost()){
            return contains(root.left, data);
        }else{
            return contains(root.right, data);
        }
    }
    // post: prints the tree contents using a preorder traversal
    public void printPreorder() {
        System.out.print("preorder:");
        printPreorder(overallRoot);
        System.out.println();
    }

    // post: prints in preorder the tree with given root
    private void printPreorder(RoomTreeNode root) {
        if (root != null) {
            System.out.print(" " + root.data);
            printPreorder(root.left);
            printPreorder(root.right);
        }
    }


    // post: prints the tree contents using an inorder traversal
    public void printInorder() {
        System.out.print("inorder:");
        printInorder(overallRoot);
        System.out.println();
    }

    // post: prints in inorder the tree with given root
    private void printInorder(RoomTreeNode root) {
        if (root != null) {
            printInorder(root.left);
            System.out.print(" " + root.data);
            printInorder(root.right);
        }
    }

    // post: prints the tree contents using a postorder traversal
    public void printPostorder() {
        System.out.print("postorder:");
        printPostorder(overallRoot);
        System.out.println();
    }

    // post: prints in postorder the tree with given root
    private void printPostorder(RoomTreeNode root) {
        if (root != null) {
            printPostorder(root.left);
            printPostorder(root.right);
            System.out.print(" " + root.data);
        }
    }
    
   

    // post: prints the tree contents, one per line, following an
    //       inorder traversal and using indentation to indicate node
    //       depth; prints right to left so that it looks correct when
    //       the output is rotated; prints "empty" for an empty tree
    public void printSideways() {
        if (overallRoot == null) {
            System.out.println("empty tree");
        } else {
            printSideways(overallRoot,0);
        }
    }

    // post: prints in reversed preorder the tree with given
    //       root, indenting each line to the given level
    private void printSideways(RoomTreeNode root, int level) {
        if (root != null) {
            printSideways(root.right, level + 1);
            for (int i = 0; i < level; i++) {
                System.out.print("    ");
            }
            System.out.println(root.data);
            printSideways(root.left, level + 1);
        }
    }
    
    
    
    public RoomTreeNode nthElement(int n, RoomTreeNode data)
{
    // We are on the correct node, return it.
    if(n == 1) // I'll make this 1 based, so passing in 1 returns the first element. 
         return data;

    // Check the left side of the tree.
    if(data.left != null) {
        RoomTreeNode o=nthElement(n-1, data.left);
        // we found the correct node.
        if(o instanceof RoomTreeNode)
            return o;
        // we didn't find it but let's count the ones we found. (This is the "Trick")
       // n=(Integer)o;
    }
    // We have no more children, let's just return our current count.
    if(data.right == null){
      return data;
     }
       // return n;
    // Recurse right
    return(nthElement(n-1, data.right));
  }
}
