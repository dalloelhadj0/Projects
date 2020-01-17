/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
EconomyRoom
*/

public class EconomyRoom extends Room {


    public EconomyRoom() {   
      super();
      setFloorOption(1);
      setRoomAvailability(true);
      setNumberGuest(2);
      setCost(100.00);
      setRoomType("economy");


       }
       
    public String getRoomType(){
      return "economy";
    }

   public String roomToFile(){
      return "Economy";
   }
   

   public String toString() {
       return  "This is an Economy room and has a capacity of " + getNumberGuest() + " people." + "The room goes for a rate of $" + getCost() +
         " and is located on floor " + getFloorOption() + ".\n" + "The room is currently " + showRoomAvailability() + ".\n";
   }






}