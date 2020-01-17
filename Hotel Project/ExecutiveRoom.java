/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
ExecutiveRoom Class
*/

public class ExecutiveRoom extends DeluxeRoom {

   private boolean jacuzzi;


   
   public ExecutiveRoom() {
   
     super();
     setRoomAvailability(true);
     setFloorOption(3);
     setNumberGuest(4);
     setCost(250.00);
     setBalcony(true);
     setKitchen(true);
     setJacuzzi(true);
     setRoomType("executive");

       }
       
       
    public boolean getJacuzzi() {
      return jacuzzi;
   }
   
   
   public String showJacuzzi() { 
      if (jacuzzi) {
         return "has a jacuzzi";
       }
   
      else {
         return "does not have a jacuzzi";
     }
  }


   public String getRoomType(){
      return "executive";
    }

   public void setJacuzzi(boolean jacuzzi) {
      this.jacuzzi=jacuzzi;
   }
   
    public boolean equals(Object o) {
      if (o instanceof ExecutiveRoom) {
         ExecutiveRoom other = (ExecutiveRoom) o;
         
        return getNumberGuest()==other.getNumberGuest() && 
            getCost()==other.getCost() && getFloorOption()==other.getFloorOption() && getRoomAvailability()==other.getRoomAvailability() &&
            getBalcony()==other.getBalcony() && getJacuzzi()==other.getJacuzzi() && getKitchen()==other.getKitchen(); 

      }
      
      else {
         return false;
      }
         
    }
   
   
   public String roomToFile(){
      return "Executive";
   }

       
   public String toString() {
    return  "This is an Executive room and has a capacity of " + getNumberGuest() + " people." + "The room goes for a rate of $" + getCost() +
      " and is located on floor " + getFloorOption() + ".\n" + "The room is currently " + showRoomAvailability() + ", " + showBalcony() + ", " +
      showJacuzzi() + " and " + showKitchen() + ".\n";
   }

}
      






