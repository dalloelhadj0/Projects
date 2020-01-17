/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
CUSTOMER CLASS
*/

import java.util.*;

public class Customer {
   
   private String firstName;
   private String lastName;
   private int membership;
   private int age;
   private Room roomPreference;
   private boolean military;
   private boolean government;
   
   
   public Customer(){
   }
   
   // customer constructor to get the customer information
   public Customer(int membership, String firstName, String lastName, int age, Room roomPreference, boolean military,
      boolean government) {
      
      setFirstName(firstName);
      setLastName(lastName);
      setMembership(membership);
      setAge(age);
      setRoomPreference(roomPreference);
      setMilitary(military);
      setGovernment(government);
    }

   
   public String getFirstName() { 
      return firstName;
   }
   
   
   public String getLastName() {
      return lastName;
   }
   
   public int getMembership() {
      return membership ;
   }
   
   public String showMembership() {
      if (membership > 0) {
         return "is member #" + membership;
      }
      else {
         return "is not a member";
      }
   }
   
   
   public int getAge() {
      return age;
   }
   

   
   public Room getRoomPreference() {
      return roomPreference;
   }
   
   public String showRoomPreference() {
      return "has a room a preference";
   }
   
   
   public boolean getMilitary(){
      return military;
   }
   
   
   public String showMilitary() {
      if (military) {
         return "has a military discount";
      }
      else {
         return "does not have a military discount";
      }
     
   }
   
   
   public boolean getGovernment() {
      return government;
    }
    
   
   public String showGovernment() {
      if (government) {
         return "has a government discount";
      }
      else {
         return "does not have a government discount";
      }
   }
   
   
   public void setFirstName(String firstName) {
   
      if (firstName == null) {
         throw new NullPointerException("First Name Required");
      }
      
      this.firstName=firstName;
   }
   
   
   public void setLastName(String lastName) {
   
      if (lastName == null) {
         throw new NullPointerException("Last Name Required");
      }
      
      this.lastName=lastName;
   }
   
   
   
   public void setMembership(int membership) {
    
      if (membership < 0) {
         throw new IllegalArgumentException("Membership Number Must Be Greater Than 0");
      }

      this.membership=membership;
   }
   
   
   
   public void setAge(int age) {
      
      if (age < 0) {
         throw new IllegalArgumentException("Please enter a valid age");
      }
   
      this.age=age;
   }
   
   
   public void setRoomPreference(Room roomPreference) {
      this.roomPreference=roomPreference;
   }
   
   
   public void setMilitary(boolean military) {
      this.military=military;
   }
   
   public void setGovernment(boolean government) {
      this.government=government;
   }
   
   public double getGovernmentDiscount(boolean value) {
      if(value==true){
         return .1;
      }
      else{
         return 0;
      }
   }
  
   public double getMembershipDiscount(boolean value) {
      if(value==true){
         return .1;
      }
      else{
         return 0;
      }
    }
      
    public boolean hasMembership() {
      if(membership > 0) {
         return true;
      }
      else{
         return false;
      }
    }
      
    public double getMilitaryDiscount(boolean value) {
       if(value==true) {
            return .1;
       }
       else {
         return 0;
       }
    }
     
       
   public String toFile() {
       return "\n" + membership + " "+ firstName + " " + lastName + " " + age + " " + roomPreference.roomToFile() + " " + military + " " + government + " " + "\n";
   }
   
   public String toString() {
      return firstName + " " + lastName + " " + showMembership() + ", is " + age + " years old.\n" + firstName + " "
      + showRoomPreference() +", " + showMilitary() + ", and " + showGovernment() + ".\n" + "\n";
  }     

}
      
   