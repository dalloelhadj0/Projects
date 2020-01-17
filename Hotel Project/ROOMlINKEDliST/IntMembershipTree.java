public class IntMembershipTree
{
  public int data;
  public IntMembershipTree left;
  public IntMembershipTree right;

   public IntMembershipTree(int data)
      {
      this(data, null, null);
      }
  public IntMembershipTree(int data, IntMembershipTree left, IntMembershipTree right)
      {
      this.data = data;
      this.left = left;
      this.right = right;
      }    
  
}