/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
Hotel Class
*/

import java.util.*;
import java.io.*;

public class Hotel {

   private LinkedRoomList hotelRooms = new LinkedRoomList();// replace the arraylist<Room> that store the rooms by a linkedList room 
   private RoomTree hotelRoomsTree = new RoomTree(); // replace the arrayList<HotelRoom> by an binary tree that is more 
                                                     //sophisticate on saving data and researching room though ou the hotel
   private LinkedCustomerList memberList = new LinkedCustomerList();   // replace the ArrayLIst<Customer> that store customer information by a linkedList Customer
   
   public Hotel() {
   }
      
   public int size() {
      return hotelRooms.size();
   }
   
   
   public Room getRoom(int i) {
      return hotelRooms.get(i);
   }
         

   public void addRoom(Room room) {
      hotelRooms.add(room);
   }
   
   public LinkedRoomList getHotelRooms() {
      return hotelRooms;
   }
   
   public void removeRoom(Room room)  {
      hotelRooms.removeRoom(room);
      
   }
   

  public int memberSize() {
      return memberList.size();
   }
   
   
   public Customer getMember(int i) {
      return memberList.get(i);
   }
        
   public void addMember(Customer member) {
      memberList.addMember(member);
   }
   
   public LinkedCustomerList getMemberList() {
      return memberList;
   }
   
   //using the removeMember fromthe linkedlIST TO DELETE information of the customer if they decide to do so
   public void removeMember(Customer member) {
      memberList.removeMember(member);
   }
   
   public void makeReservation(Room room) {
      room.setRoomAvailability(false);
   }
   
   public void cancelReservation(Room room) {
         room.setRoomAvailability(true);

   }
   
   public double calculateCost(Room room,int nights, Customer customer) {
      double discounts = room.getCost() * nights * (double)(customer.getMembershipDiscount(customer.hasMembership()) + 
         customer.getMilitaryDiscount(customer.getMilitary()) + customer.getGovernmentDiscount(customer.getGovernment()));
         
      return room.getCost() * nights - discounts;
   }
      

   public void makePayment(boolean value,Room room) {
      if (value==false) {
         cancelReservation(room);
         System.out.println("You're payment has been cancelled. Thank you.");
      }
      
      if (value==true) {
         makeReservation(room);
         System.out.println("You're payment has been received. Thank you!");
      }
   }
   
   // display the billing to the customer to see his/her bill
   public void printReceipt(Room room, int nights, Customer customer,String roomNumber){
      System.out.println( "Thank you for staying at Mamou Hotels. Here is a summary of your stay. \n" + 
         "You are staying " + nights + " nights in our " + room.roomToFile() + " Room, "+ roomNumber +", for a total of: $" + calculateCost(room,nights,customer));
   } 

   public String toString() {
      return "This is a list of our members: \n "+ memberList + "\n" + "This is a list of our rooms: " + "\n" + hotelRooms;
   }
   

      
   
      
 }

  

 
 
 
 
 
 
 







