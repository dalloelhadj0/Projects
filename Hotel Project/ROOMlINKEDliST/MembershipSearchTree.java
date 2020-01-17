
// ELHADJ DIALLO
// CSC 143
// Binary search tree that display the customer membership a

import java.util.*;
public class MembershipSearchTree {
    private IntMembershipTree overallRoot;

    // post: constructs an empty tree
    public MembershipSearchTree() {
        overallRoot = null;
    }
    
    // pre : tree is a binary search tree
    // post: value is added to overall tree so as to preserve the binary search
    //       tree property
    public void add(int value) {
        overallRoot = add(overallRoot, value);
    }

    // post: value is added to given binary search tree so as to preserve the
    //       binary search tree property
    private IntMembershipTree add(IntMembershipTree root, int value) {
        if (root == null) {
            root = new IntMembershipTree(value);
        } else if (value <= root.data) {
            root.left = add(root.left, value);
        } else {
            root.right = add(root.right, value);
	}
        return root;
 }

   public boolean contains(int value){
      return contains(overallRoot, value);
      }
      
   private boolean contains(IntMembershipTree root, int value){
      if(root == null){
      return true;
    }else if( value== root.data){
    return true;
    }else if(value < root.data){
    return contains(root.left, value);
    }else{
    return contains(root.right, value);
    } 
 }
 

    
// return the total nuber of members in the tree
public int countLeftNodes() {
    return countLeftNodes(overallRoot);
}

private int countLeftNodes(IntMembershipTree node) {
    if(node == null)
        return 0;
        
    int count = countLeftNodes(node.right);
    if(node.left != null)
        count += 1 + countLeftNodes(node.left);
    return count;
}

      // post: prints the tree contents using a preorder traversal
    public void printPreorder() {
        System.out.print("preorder:");
        printPreorder(overallRoot);
        System.out.println();
    }

    // post: prints in preorder the tree with given root
    private void printPreorder(IntMembershipTree root) {
        if (root != null) {
            System.out.print(" " + root.data);
            printPreorder(root.left);
            printPreorder(root.right);
        }
    }
    


    // post: prints the tree contents using an inorder traversal
    public void printInorder() {
        System.out.print("");
        printInorder(overallRoot);
        System.out.println();
    }

    // post: prints in inorder the tree with given root
    private void printInorder(IntMembershipTree root) {
        if (root != null) {
            printInorder(root.left);
            System.out.print(" " + root.data);
            printInorder(root.right);
        }
    }

    // post: prints the tree contents using a postorder traversal
    public void printPostorder() {
        System.out.print("");
        printPostorder(overallRoot);
        System.out.println();
    }

    // post: prints in postorder the tree with given root
    private void printPostorder(IntMembershipTree root) {
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
            printSideways(overallRoot, 0);
        }
    }

    // post: prints in reversed preorder the tree with given
    //       root, indenting each line to the given level
    private void printSideways(IntMembershipTree root, int level) {
        if (root != null) {
            printSideways(root.right, level + 1);
            for (int i = 0; i < level; i++) {
                System.out.print("    ");
            }
            System.out.println(root.data);
            printSideways(root.left, level + 1);
        }
    }
}