/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
RoomTreeNode class
*/
public class RoomTreeNode
{
  public Room data; // Room data stored in this node
  public RoomTreeNode left;// link to left next node in the list
  public RoomTreeNode right; // link to right next node in the list

   //default constructor
   public RoomTreeNode(Room data)
      {
      this(data, null, null);
      }
      
      // constructor for adding Room data into a binarySearch tree to control
      // how many room we do have overrall iin side out hotel
  public RoomTreeNode(Room data, RoomTreeNode left, RoomTreeNode right)
      {
      this.data = data;
      this.left = left;
      this.right = right;
      }    
  
}