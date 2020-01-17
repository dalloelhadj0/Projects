/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
LinkedRoomList class that has different
methods that can be used to mutate
and access datas.
*/

public class LinkedRoomList{
   
   private RoomListNode front; // Node that store the Room and pointing to the next node
  
  // default constructor helps us point the front to null
   public LinkedRoomList(){
      front = null;
   }
   public String toString() { // Returns the list as a string.
      
      if(front == null){
         return "[]";
      } else {
         String result = "" + front.data;
         
         RoomListNode current = front.next;
         
         while(current !=null) {
            result += ", " + current.data;
            current = current.next;
         }
         result +="";
         return result;
         }
   }
   public int size(){ // Returns the size of the list
      int count = 0;
      RoomListNode current = front;
      
      while(current!=null){
         current = current.next;
         count++;
      }
      return count;
   }
   public Room get(int index){ // Returns the customer given index
      RoomListNode current = front;
      for(int i = 0; i<index; i++){
         current = current.next;
       }
      return current.data;
    }

   public void add(Room member){ // Adds a customer object into a linkedlist of room

      if(front==null){
         front = new RoomListNode(member);
      }
      else{
         RoomListNode current = front;
         while(current.next!=null){
            current = current.next;
          }
      current.next = new RoomListNode(member);
      
      }
  }
   
      public void set(int index, Room room){ // Sets a given index to a customer object
      RoomListNode current = front;
         for(int i = 0; i <index; i++){
            current = current.next;
            }
         current.next = new RoomListNode(room);
         }
     
     public void add(int index, Room data){ // Adds a customer object at a given given index
         
         RoomListNode current = front;
         if(index == 0){
            front = new RoomListNode(data, front);
         }
         else { 
               
               for(int i = 0; i<index - 1; i++){
                  
                  current = current.next;
               }
                  current.next = new RoomListNode(data, current.next);
              }
    }
     
     
     public void remove(int index){ // Removes a cusomer object given index
         if(index == 0){
            front = front.next;
         }else{
            RoomListNode current = front;
          for(int i = 0; i<index-1; i++){
            current = current.next;
            }
            current.next = current.next.next;
 
          }
     } 

     public void removeRoom(Room room){ //remove a givin room from  the linkedLIst
        RoomListNode current = front;     
       while(!current.next.data.equals(room)){
        
               current = current.next;
           }
           
           current.next=current.next.next;
           current.next=null;
           
        }
        
     
    
     private RoomListNode nodeAt(int index){ // Returns the customer object given index
        RoomListNode current = front;     
        for(int i = 0; i < index; i++){
            current = current.next;
      }
      return current;
    }   
}
 
   

   
 
    
    