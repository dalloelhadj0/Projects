/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
ListNode class for LinkedCustomer 
List to store Customer object
*/

//Thsi class helps us get control the Customer data whithout making 
//the program so vilnerable on some basis of the program
public class ListNode{
   public Customer data;
   public ListNode next;
   
   
   public ListNode(Customer data){
      this(data,null);
   }
   // constructor of the ListNode helping us to add element using this constructor into the LinkedLIst
   public ListNode(Customer data, ListNode next){
      this.data = data;
      this.next = next;
   }
}
   
   
   