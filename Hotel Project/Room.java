/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
Room Class
*/

import java.util.*;

public class Room {

   private int numberGuest;
   private double cost;
   private int floorOption;
   private boolean roomAvailability;
   private boolean balcony;
   private boolean jacuzzi;
   private boolean kitchen;
   private String roomType;
   
   public Room(){
     this(0,0.0,0,false,false,false,false,"");

   }
    
    // Room constructor helping us add room inside the hotel for expending it
   public Room(int numberGuest, double cost, int floorOption, boolean RoomAvailability,boolean balcony,boolean jacuzzi, boolean kitchen,String roomType) {
      this.numberGuest = numberGuest;
      this.cost=cost;
      this.floorOption=floorOption;
      this.roomAvailability=roomAvailability;
      this.balcony=balcony;
      this.jacuzzi=jacuzzi;
      this.kitchen=kitchen;
      this.roomType=roomType;
   }
     
   public int getNumberGuest() {
      return numberGuest;
   }
   
   public String getRoomType() {
      return "";
    }
   
   public void setRoomType(String roomType) {
      this.roomType=roomType;
   }

   public double getCost() {
      return cost;
   }
   
   
   public int getFloorOption() {
      return floorOption;
   }
   
   public boolean getRoomAvailability() {
      return roomAvailability;
   }
   
   
   public String showRoomAvailability() {
      if (roomAvailability) {  
         return "available";
       }
       
       else {
         return "unavailable";
       }
         
   }
   
   
    
   public void setNumberGuest(int numberGuest) {
      
      if (numberGuest < 0 || numberGuest > 4) {
         throw new IllegalArgumentException("Guests Exceed Capacity");
      }

      this.numberGuest=numberGuest;
   }

   public void setCost(double cost) {
         
      if (cost < 0) {
         throw new IllegalArgumentException("Cost Cannot Be Less than 0");
      }

      this.cost=cost;
    }
   
      
   public void setFloorOption(int floorOption) {
      
      if (floorOption < 0 || floorOption > 3) {
         throw new IllegalArgumentException("Invalid Floor Number");
      }

   
      this.floorOption=floorOption;
   }
   
   
   public void setRoomAvailability(boolean roomAvailability) {
      this.roomAvailability=roomAvailability;
   }
   
    public boolean equals(Object o) {
      if (o instanceof Room) {
         Room other = (Room) o;
         
        return getNumberGuest()==other.getNumberGuest() && 
            getCost()==other.getCost() && getFloorOption()==other.getFloorOption() && getRoomAvailability()==other.getRoomAvailability(); 

      }
      
      else {
         return false;
      }
         
    }

    public boolean getBalcony(){
      return balcony;
    }
    
    public String showBalcony(){
      return "does not have a balcony";
    }
    
    public void setBalcony(boolean value){
      
    }
    
     public boolean getJacuzzi(){
      return jacuzzi;
    }
    
    public String showJacuzzi(){
      return "does not have a jacuzzi";
    }
    
    public void setJacuzzi(boolean value) {
    }
    
    public boolean getKitchen(){
      return kitchen;
    }
    
    public String showKitchen(){
      return "does not have a kitchen";
    }
    
    public void setKitchen(boolean value) {
    }


   public String roomToFile(){
      return "Room";
   }
   
   public String toString() {
   
   return "This room is currently being remodeled.\n";
   }
        
   
 }
    
      