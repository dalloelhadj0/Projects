/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
DeluxeRoom Class
*/


public class DeluxeRoom extends EconomyRoom {
   private boolean balcony;
   private boolean kitchen;

   public DeluxeRoom() {
   
     super();
     setRoomAvailability(true);
     setFloorOption(2);
     setNumberGuest(3);
     setCost(180.00);
     setBalcony(true);
     setKitchen(true);
     setRoomType("deluxe");

       }
       
         
   public void setBalcony(boolean balcony) {
      this.balcony=balcony;
   }
      
   
   public void setKitchen(boolean kitchen) {
      this.kitchen=kitchen;
   }
   

       
    public boolean getBalcony() {
      return balcony;
   }
   
   
   public String showBalcony() {
      if (balcony) { 
         return "has a balcony";
      }
      
      else {
         return "does not have a balcony";
      }
      
   }
   
   public String getRoomType(){
      return "deluxe";
    }
   
   public boolean getKitchen() {
      return kitchen;
   }
   
   
   public String showKitchen() {
      if (kitchen) { 
         return "has a kitchen";
      }
      
      else {
         return "does not have a kitchen";
      }
   }
   
   
   public boolean equals(Object o) {
      if (o instanceof DeluxeRoom) {
         DeluxeRoom other = (DeluxeRoom) o;
         
        return getNumberGuest()==other.getNumberGuest() && 
            getCost()==other.getCost() && getFloorOption()==other.getFloorOption() && getRoomAvailability()==other.getRoomAvailability() &&
            getBalcony()==other.getBalcony() && getKitchen()==other.getKitchen(); 

      }
      
      else {
         return false;
      }
         
    }

   public String roomToFile(){
      return "Deluxe";
   }
     

   public String toString() {
      return  "This is a Deluxe room and has a capacity of people " + getNumberGuest() + "." + "The room goes for a rate of $" + getCost() + 
      " and is located on floor " + getFloorOption() + ".\n" + "The room is currently " + showRoomAvailability() + ", " + showBalcony() + " and " + showKitchen() + ".\n";
   }


   



}