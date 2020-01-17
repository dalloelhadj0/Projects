/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
LinkedCustomerList class that has different
methods that can be used to mutate
and access datas.
*/

public class LinkedCustomerList extends Customer{
   
   private ListNode front; // Listnode that stoire data customer
  
   //default cunstructor
   public LinkedCustomerList(){
      front = null;
   }
   public String toString() { // Returns the list of customer as a string.
      
      if(front == null){
         return "";
      } else {
         String result =""+ front.data;
         
         ListNode current = front.next;
         
         while(current !=null) {
            result += ", " + current.data;
            current = current.next;
         }
         return result;
         }
   }
   
   public int size(){ // Returns the size of the list
      int count = 0;
      ListNode current = front;
      
      while(current!=null){
         current = current.next;
         count++;
      }
      return count;
   }
   public Customer get(int index){ // Returns the customer given index
      ListNode current = front;
      for(int i = 0; i < index; i++){
         current = current.next;
       }
      return current.data;
    }

   public void addMember(Customer member){ // Adds a customer object into a list

      if(front==null){
         front = new ListNode(member);
      }
      else{
         ListNode current = front;
         while(current.next!=null){
            current = current.next;
          }
      current.next = new ListNode(member);
      
      }
  }
   
      public void set(int index, Customer value){ // Sets a given index to a customer object
      
      ListNode current = front;
         for(int i = 0; i <index; i++){
            current = current.next;
            }
         current.next = new ListNode(value);
         }
     
     public void add(int index, Customer value){ // Adds a customer object at a given given index
         
         ListNode current = front;
         if(index == 0){
            front = new ListNode(value, front);
         }
         else { 
               
               for(int i = 0; i<index - 1; i++){
                  
                  current = current.next;
               }
                  current.next = new ListNode(value, current.next);
              }
    }
     
     
     public void remove(int index){ // Removes a cusomer object given index
         if(index == 0){
            front = front.next;
         }else{
            ListNode current = front;
          for(int i = 0; i<index-1; i++){
            current = current.next;
            }
            current.next = current.next.next;
 
          }
     }    
     
     public void removeMember(Customer value){ // remove a member that decide no longer to be part of our hotel using his membership number
        ListNode current = front;
        
        if(this.getMembership()==value.getMembership()){
               current.next = current.next.next;
           }
        }
    
     private ListNode nodeAt(int index){ // Returns the customer object given index
        ListNode current = front;     
        for(int i = 0; i < index; i++){
            current = current.next;
      }
      return current;
    }   
}
 
   

   
 
    
    