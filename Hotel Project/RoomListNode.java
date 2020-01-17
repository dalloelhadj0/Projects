/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
RoomLIstNode class to store 
list of Room object
*/
public class RoomListNode {
    public Room data;       // data stored in this node
    public RoomListNode next;  // link to next node in the list


    // post: constructs a node with given data and null link
    public RoomListNode(Room data) {
        this(data, null);
    }

    // post: constructs a node with given data and given link
    public RoomListNode(Room data, RoomListNode next) {
        this.data = data;
        this.next = next;
    }
}