/*
Elhadj Diallo
CSC#143 Winter@2019
NORTH SEATTLE
Hotel Project
Hotel Class
*/

import java.util.*;
import java.io.*;
import java.awt.*;

public class HotelMain {

// In this main we use all the classes to manage and manupulate the data that we need
//to build a very efficient safe, working and consistant hotel that every body will like to lease wuth us
public static void main(String[] args) throws FileNotFoundException {
hotelGreeting();


}

  public static void hotelGreeting() throws FileNotFoundException {
   
 
    Hotel hotel1 = new Hotel();
    Hotel memberList1 = new Hotel();
    
    Room Room= new Room();
    Customer Customer = new Customer();
    hotel1.addRoom(Room);
    memberList1.addMember(Customer);
    
    EconomyRoom EconomyCompare = new EconomyRoom();
    DeluxeRoom DeluxeCompare = new DeluxeRoom();
    ExecutiveRoom ExecutiveCompare = new ExecutiveRoom();
    Room tempRoomPreference = new Room();
    
    Room reservedRoom= new Room();
    Room fileRoomPreference= Room;
   
    Customer NewCustomer = new Customer();
    LinkedCustomerList memberList = new LinkedCustomerList();   

    int durationOfStay = 0;
    String roomNumber="";   
    File membership = new File("MembershipFile.txt");
    readFromFile("MembershipFile.txt",memberList1); 
   
    ExecutiveRoom room1= new ExecutiveRoom();
    ExecutiveRoom room2= new ExecutiveRoom();
    ExecutiveRoom room3= new ExecutiveRoom();
    EconomyRoom room4= new EconomyRoom();
    EconomyRoom room5= new EconomyRoom();
    EconomyRoom room6= new ExecutiveRoom();
    DeluxeRoom room7= new DeluxeRoom();
    DeluxeRoom room8= new DeluxeRoom();
    
    String Economy = "Our Economy Room offers comfortable budget friendly accomodation. The room has an occupancy of 2 people, and the rate is $100 a night.";
    String Deluxe = "Our Deluxe Room is a spacious lodging that offers a kitchen and balcony with views from the second floor.\n This room has an occupancy " +
         "of 3 people, and the rate is $180 a night.";
    String Executive = "Our Executive Room is an enormous room with a full kitchen, a balcony with ocean views from the third floor, and a private jacuzzi.\n"+
         "This room has an occupancy of 4 people and a rate of $250 a night.";

    hotel1.addRoom(room1);
    hotel1.addRoom(room2);
    hotel1.addRoom(room3);
    hotel1.addRoom(room4);
    hotel1.addRoom(room5);
    hotel1.addRoom(room6);
    hotel1.addRoom(room7);
    hotel1.addRoom(room8);
    //===========================================================================
        RoomTree hotelRoomsTree = new RoomTree(); // the tree store all room in the hotel and we an just 
        //expends the hotel by adding into the tree some new room using the add methode that we creat into the RoomTree class
        // also the tree help us get the total room that we have in our hotel
        hotelRoomsTree.add(room1);
        hotelRoomsTree.add(room2);
        hotelRoomsTree.add(room3);
        hotelRoomsTree.add(room4);
        hotelRoomsTree.add(room5);
        hotelRoomsTree.add(room6);
        hotelRoomsTree.add(room7);
        hotelRoomsTree.add(room8);
        
       // hotelRoomsTree.printPostorder();
       // hotelRoomsTree.printSideways();
        System.out.println("Welcome to Mamou Hotels!");
        System.out.println("Mamou Hotel is known for his large community and its best carrying and serving their Customer.\nWe currently have " + hotelRoomsTree.countNodes() + " variety rooms that we use in our hotel to better serves your needs");
        System.out.println("We continue growing every year which help us gives you a confortable environment with all your need in place ");
   //===========================================================================
      
      Scanner input = new Scanner(System.in);
  
      System.out.println();
       

      System.out.println("So let's get Started\nIs this your first time visiting our hotel?");
      String userFirstTime=input.next();
         
       while(!(userFirstTime.toLowerCase().startsWith("y") || userFirstTime.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            userFirstTime=input.next();
       }
       
       if(userFirstTime.toLowerCase().startsWith("y")) {
            System.out.println("Again Welcome to Mamou Hotel.");
            System.out.println("We offer three styles of rooms. We have Economy, Deluxe, and Executive rooms available.");
            System.out.println("For more information about a room, enter the style of room (no to exit.)");
            
            String userRoomView=input.next();
            
            while(!(userRoomView.toLowerCase().equals("economy") || userRoomView.toLowerCase().equals("deluxe") || userRoomView.toLowerCase().equals("executive") ||
             userRoomView.toLowerCase().startsWith("n"))) {
             
               System.out.println("Please enter Economy, Deluxe, or Executive.");
               userRoomView=input.next();
           }
           
         while(!(userRoomView.toLowerCase().startsWith("n"))){
         
            if(userRoomView.toLowerCase().equals("economy")) {
               System.out.println(Economy);
           }
            if(userRoomView.toLowerCase().equals("deluxe")) {
               System.out.println(Deluxe);
           }
           
           if(userRoomView.toLowerCase().equals("executive")) {
               System.out.println(Executive);
           }
           System.out.println();
           System.out.println("Would you like to view another room? If so, enter the room type. If not, just enter no.");
           userRoomView=input.next();
         }
          
        System.out.println("Would you like to reserve a room with us? If so, type the style of room you'd like, and we'll check for availability.\n");
            
         userRoomView=input.next();
         tempRoomPreference=Room;
         
        while(!(userRoomView.toLowerCase().equals("economy") || userRoomView.toLowerCase().equals("deluxe") || userRoomView.toLowerCase().equals("executive") || 
             userRoomView.toLowerCase().startsWith("n"))) {
             
             System.out.println("Please enter Economy, Deluxe, or Executive. Or enter no to exit");
             userRoomView=input.next();
         }
         
        if(userRoomView.toLowerCase().equals("economy")) {
            for(int i = 0; i < hotel1.size(); i++) {
               if(hotel1.getRoom(i).getRoomAvailability()==true && hotel1.getRoom(i).getRoomType().equals("economy")) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  roomNumber="Room "+ i;
                  tempRoomPreference=EconomyCompare;
                  
                  i=hotel1.size();
                }
            }
        }
        
        if(userRoomView.toLowerCase().equals("deluxe")) {
            for(int i = 0; i < hotel1.size(); i++) {
               if(hotel1.getRoom(i).getRoomAvailability()==true && hotel1.getRoom(i).getRoomType().equals("deluxe")) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  roomNumber="Room "+ i;
                  tempRoomPreference=DeluxeCompare;
           
                  i=hotel1.size();
                }
            }
        }
        
         if(userRoomView.toLowerCase().equals("executive")) {
            for(int i = 0; i < hotel1.size(); i++) {
               if(hotel1.getRoom(i).getRoomAvailability()==true && hotel1.getRoom(i).getRoomType().equals("executive")) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  roomNumber="Room "+ i;
                  tempRoomPreference=ExecutiveCompare;
     
                  i=hotel1.size();
                }
            }
        }
          if(userRoomView.toLowerCase().startsWith("n")) {
            hotelGreeting();
            System.exit(0);
     
      }
     

        
        System.out.println("Thanks for choosing Mamou Hotels. We just need a little more information from you.");
         
         System.out.println("How many nights are you staying?");
          String testDurationOfStay="";

        
          while(testDurationOfStay !="!PASS!"){

            if(input.hasNextInt()){
                  durationOfStay= input.nextInt();
                  
                  if((durationOfStay > 0) && (durationOfStay < 160)){
                     testDurationOfStay="!PASS!";
                  }
                  else{
                     System.out.println("Please enter a valid number of nights.");
                  }
              }
            else{
               System.out.println("Please enter a valid number of nights.");
               testDurationOfStay  = input.next();
    
           } 
         }
         

         validateInfo(input, durationOfStay,tempRoomPreference,memberList1,NewCustomer);
     
       System.out.println("Your room is booked.You're in "+ roomNumber + ". To finalize your payment of $" + 
       hotel1.calculateCost(reservedRoom,durationOfStay,memberList1.getMember(memberList1.memberSize()-1)) +" please enter yes. To cancel, enter no.");
       
       String paymentString = input.next();
       boolean payment=false;
         
       while(!(paymentString.toLowerCase().startsWith("y") || paymentString.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            paymentString = input.next();
         }
         
         if(paymentString.toLowerCase().startsWith("y")) {
            payment=true;
            hotel1.makePayment(payment,reservedRoom);
            hotel1.printReceipt(reservedRoom,durationOfStay,memberList1.getMember(memberList1.memberSize()-1),roomNumber);

         }
         
         if(paymentString.toLowerCase().startsWith("n")) {
            payment=false;
            hotel1.makePayment(payment,reservedRoom);
            hotelGreeting();

         }                
      }
      
      if(userFirstTime.toLowerCase().startsWith("n")) {
         System.out.println("Welcome back! Do you have a membership with us?");
         String stringMembership = input.next();
         
         while(!(stringMembership.toLowerCase().startsWith("y") || stringMembership.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            stringMembership= input.next();
          }
          
          if(stringMembership.toLowerCase().startsWith("y")) {
          
            System.out.println("Great, please enter your membership number.");
            String testMembership="";
            int membershipNumber =0;

        
          while(!(testMembership.equals("!PASS!"))) {
            if(input.hasNextInt()){
                  membershipNumber= input.nextInt();
                  
                  if(membershipNumber > 0 && membershipNumber < memberList1.memberSize()){
                     for(int i = 0; i < memberList1.memberSize() ; i++) {
                        if(membershipNumber==memberList1.getMember(i).getMembership()) {
                           NewCustomer = memberList1.getMember(i);
                           testMembership = "!PASS!";
                        }
                        
                     }
                  } 
                 else{
                      System.out.println("Please enter a valid membership number.");
                 }
            }
            else{
               System.out.println("Please enter a valid membership number.");
                testMembership = input.next();
            }
            if(testMembership.toLowerCase().equals("no")){
               hotelGreeting();
               System.exit(0);
             }
         }
         
      System.out.println("Would you like to modify your membership info? Enter \"Modify\" to change, \"Cancel\" to cancel your membership, or no to continue.");
      String modifyResponse = input.next();
         while(!(modifyResponse.toLowerCase().equals("modify") || modifyResponse.toLowerCase().equals("cancel") || modifyResponse.toLowerCase().startsWith("n"))){
            System.out.println("Please enter Modify or Cancel.");
            modifyResponse = input.next();
         }
         
         if(modifyResponse.toLowerCase().equals("cancel")){
            System.out.println("Your membership has been cancelled.");
            hotel1.removeMember(NewCustomer);
            hotelGreeting();
         }
         if(modifyResponse.toLowerCase().equals("modify")){
            hotel1.removeMember(NewCustomer);
            validateInfo(input, durationOfStay,tempRoomPreference,memberList1,NewCustomer);
            
          }
   
         
       System.out.println("Would you like to make a reservation based on your preferences?"); 
       String prefAnswer = input.next();
         
         while(!(prefAnswer.toLowerCase().startsWith("y") || prefAnswer.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            prefAnswer = input.next();
         }
         
         
         if(prefAnswer.toLowerCase().startsWith("y")) {
         
         
         
         System.out.println("How many nights are you staying?");
          String testDurationOfStay="";

        
          while(testDurationOfStay !="!PASS!"){

            if(input.hasNextInt()){
                  durationOfStay= input.nextInt();
                  
                  if((durationOfStay > 0) && (durationOfStay < 160)){
                     testDurationOfStay="!PASS!";
                  }
                  else{
                     System.out.println("Please enter a valid number of nights.");
                  }
              }
            else{
               System.out.println("Please enter a valid number of nights.");
               testDurationOfStay  = input.next();
    
           } 
         }

         
            for(int i = 0; i < hotel1.size(); i++) {
               if(NewCustomer.getRoomPreference().equals(hotel1.getRoom(i))) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  roomNumber="Room "+ i;

                  
                  i=hotel1.size();
                }
             }
             
        
       System.out.println("Thank you," + NewCustomer.getFirstName() + ". Your room is booked.You're in  " + roomNumber + ". To finalize your payment of $" + hotel1.calculateCost(reservedRoom,durationOfStay,NewCustomer) +" please enter yes. To cancel, enter no.");
       String paymentString = input.next();
       boolean payment=false;
         
       while(!(paymentString.toLowerCase().startsWith("y") || paymentString.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            paymentString = input.next();
         }
         
         if(paymentString.toLowerCase().startsWith("y")) {
            payment=true;
            hotel1.makePayment(payment,reservedRoom);
            hotel1.printReceipt(reservedRoom,durationOfStay,NewCustomer,roomNumber);
            System.exit(0);

         }
         
         if(paymentString.toLowerCase().startsWith("n")) {
            payment=false;
            hotel1.makePayment(payment,reservedRoom);
            hotelGreeting();
            System.exit(0);

         }  
      
      }  
      if(prefAnswer.toLowerCase().startsWith("n")) {
         chooseRoom(input,Executive,Deluxe,Economy,memberList1,hotel1,Room,EconomyCompare,DeluxeCompare,ExecutiveCompare,reservedRoom,durationOfStay,NewCustomer,roomNumber);
       }
       
      }
      
       else if(stringMembership.toLowerCase().startsWith("n")) {
         chooseRoom(input,Executive,Deluxe,Economy,memberList1,hotel1,Room,EconomyCompare,DeluxeCompare,ExecutiveCompare,reservedRoom,durationOfStay,NewCustomer,roomNumber);
  

     }
   
 
   }
  } 
   public static void readFromFile(String fileName,Hotel memberList1)
      throws FileNotFoundException {
      
     EconomyRoom EconomyCompare = new EconomyRoom();
     DeluxeRoom DeluxeCompare = new DeluxeRoom();
     ExecutiveRoom ExecutiveCompare = new ExecutiveRoom();
     boolean fileMilitary;
     boolean fileGovernment;
  
    Room fileRoomPreference = new Room();
    File membership = new File(fileName);
    
    Scanner readFile = new Scanner(membership);
    
      while (readFile.hasNext()) {
         int fileMembership = readFile.nextInt();
         String fileFirstName = readFile.next();
         String fileLastName = readFile.next();
         int fileAge= readFile.nextInt();
         String fileRoomPrefTest = readFile.next();
         String fileMilitaryTest = readFile.next();
         String fileGovernmentTest = readFile.next();
      
         if(fileRoomPrefTest.equals("Economy")) {
           fileRoomPreference = EconomyCompare;
         }
         else if(fileRoomPrefTest.equals("Deluxe")) {
           fileRoomPreference = DeluxeCompare;
         }
         else if(fileRoomPrefTest.equals("Executive")) {
             fileRoomPreference = ExecutiveCompare;
       } 
        
       
       if (fileMilitaryTest.equals("true")) {
           fileMilitary = true;
       }
       else{
          fileMilitary = false;
      }
      
       if (fileGovernmentTest.equals("true")) {
           fileGovernment = true;
       }
       else{
           fileGovernment = false;
      }
       memberList1.addMember(new Customer(fileMembership,fileFirstName,fileLastName,fileAge,fileRoomPreference,fileMilitary,fileGovernment));
       //System.out.println(memberList.toString());
       //=========================================================================================
      }
   }   
   
   public static void validateInfo(Scanner input,int durationOfStay,Room tempRoomPreference, Hotel memberList1,Customer NewCustomer) throws FileNotFoundException{
      System.out.println("Your first name?");
        String tempFirstName=input.next();
        
        while(tempFirstName.equals("0") || tempFirstName.startsWith("2") || tempFirstName.startsWith("3") || tempFirstName.startsWith("4") || tempFirstName.startsWith("5") ||
            tempFirstName.startsWith("6") || tempFirstName.startsWith("7") || tempFirstName.startsWith("8") || tempFirstName.startsWith("9") || tempFirstName.startsWith("1"))
             {
             
            System.out.println("Please enter a valid name.");
            tempFirstName=input.next();
        }
        
        
        
           System.out.println("Last name?"); 
           String tempLastName=input.next();
        
        while(tempLastName.equals("0") || tempLastName.startsWith("2") || tempLastName.startsWith("3") || tempLastName.startsWith("4") || tempLastName.startsWith("5") ||
            tempLastName.startsWith("6") || tempLastName.startsWith("7") || tempLastName.startsWith("8") || tempLastName.startsWith("9") || tempLastName.startsWith("1"))
             {
             
             System.out.println("Please enter a valid name.");
             tempLastName=input.next();
         }
         
          
        System.out.println("Now, enter your age.");
        String testAge="";
        int tempAge=0;

        
          while(testAge !="!PASS!"){

            if(input.hasNextInt()){
                  tempAge= input.nextInt();
                  
                  if((tempAge > 0) && (tempAge < 160)){
                     testAge="!PASS!";
                  }
                  else{
                     System.out.println("Please enter a valid age.");
                  }
            }
            else{
               System.out.println("Please enter a valid age.");
               testAge = input.next();
            }
            
         }
         
         
         System.out.println("Are you a government employee?");
         String governmentEmployment = input.next();
         boolean tempGovernment=false;
         
          while(!(governmentEmployment.toLowerCase().startsWith("y") || governmentEmployment.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            governmentEmployment = input.next();
          }
         
         if (governmentEmployment.toLowerCase().startsWith("y")) {
            tempGovernment = true;
         }

             
            
        
         
         System.out.println("Are you in the military?");
         String militaryEmployment = input.next();
         boolean tempMilitary=false;
         
          while(!(militaryEmployment.toLowerCase().startsWith("y") || militaryEmployment.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            militaryEmployment = input.next();
          }
         
         if (militaryEmployment.toLowerCase().startsWith("y")) {
            tempMilitary = true;
         }
         
         
        System.out.println("Would you like to become a member?\n" +
            "With membership, we'll keep your information to a secure place, and offer discounted rates.");    
            String tempMembershipString = input.next();   
            int tempMembership=0;
          
         while(!(tempMembershipString.toLowerCase().startsWith("y") || tempMembershipString.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            tempMembershipString = input.next();
         }
         
         if (tempMembershipString.toLowerCase().startsWith("y")) {
             tempMembership = memberList1.getMember(memberList1.memberSize()-1).getMembership() + 1;
            
            
            NewCustomer = new Customer(tempMembership,tempFirstName, tempLastName,tempAge,tempRoomPreference,tempMilitary,tempGovernment);
            System.out.println(NewCustomer);
            
            System.out.println("Is this information correct?");
            String validateInfo=input.next();
         
            while(!(validateInfo.toLowerCase().startsWith("y") || validateInfo.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            validateInfo = input.next();
         }

            if (validateInfo.toLowerCase().startsWith("y")) {
               memberList1.addMember(NewCustomer);
               
               
               try { 
  
               // Open given file in append mode. 
               BufferedWriter out = new BufferedWriter( 
                   new FileWriter("MembershipFile.txt", true)); 
                   out.write("\n" + NewCustomer.toFile() + "\n"); 
                   out.close(); 
              } 
              catch (IOException e) { 
               System.out.println("exception occurred" + e); 
              } 
              
              System.out.println("Thanks for joining, " + tempFirstName+"!\nYou're information has been saved. Please remember your membership number for future reference.\n" );
             // System.out.print("Congratulation, you are one of OURS now and your membership is #: ");
              System.out.println();
               
           }
            
            if(validateInfo.toLowerCase().startsWith("n")){
                  validateInfo(input, durationOfStay,tempRoomPreference,memberList1,NewCustomer);

         }   

      }
      if (tempMembershipString.toLowerCase().startsWith("n")) {
            NewCustomer= new Customer(tempMembership,tempFirstName, tempLastName,tempAge,tempRoomPreference,tempMilitary,tempGovernment);
           
           System.out.println(NewCustomer.getFirstName() +" " + NewCustomer.getLastName()+ " is " + NewCustomer.getAge() +",  " +
               NewCustomer.showMilitary() + ", and " + NewCustomer.showGovernment() + ".");
          
            
            System.out.println("Is this information correct?");
            String validateInfo=input.next();
            
            while(!(validateInfo.toLowerCase().startsWith("y") || validateInfo.toLowerCase().startsWith("n"))){
               System.out.println("Please enter yes or no.");
               validateInfo = input.next();
            }
         
            if(validateInfo.toLowerCase().startsWith("n")){
                  validateInfo(input, durationOfStay,tempRoomPreference,memberList1,NewCustomer);

            }   

       }
       
    }

      
    
    public static void chooseRoom(Scanner input,String Executive,String Deluxe,String Economy,Hotel memberList1,
         Hotel hotel1,Room Room,Room EconomyCompare, Room DeluxeCompare, Room ExecutiveCompare, Room reservedRoom,int durationOfStay, Customer NewCustomer,String roomNumber)
            throws FileNotFoundException {

         System.out.println("We offer three styles of rooms. We have Economy, Deluxe, and Executive rooms available.");
            System.out.println("For more information about a room, simply enter the style of room that you'd like. (e.g. Economy to view an Economy room)\n" +
            "Or, enter no to exit.");
            
            String userRoomView=input.next();
            
            while(!(userRoomView.toLowerCase().equals("economy") || userRoomView.toLowerCase().equals("deluxe") || userRoomView.toLowerCase().equals("executive") ||
             userRoomView.toLowerCase().startsWith("n"))) {
             
               System.out.println("Please enter Economy, Deluxe, or Executive.");
               userRoomView=input.next();
           }
           
         while(!(userRoomView.toLowerCase().startsWith("n"))){
         
            if(userRoomView.toLowerCase().equals("economy")) {
               System.out.println(Economy);
           }
            if(userRoomView.toLowerCase().equals("deluxe")) {
               System.out.println(Deluxe);
           }
           
           if(userRoomView.toLowerCase().equals("executive")) {
               System.out.println(Executive);
           }
           
           System.out.println();
           System.out.println("Would you like to view another room? If so, enter the room type. If not, just enter no.");
               userRoomView=input.next();
        }
        
        System.out.println();
        System.out.println("Would you like to reserve a room with us? If so, type the style of room you'd like, and we'll check for availability.\n"+
            "If not, enter no, and we hope you consider us in the future.");
            
         userRoomView=input.next();
         Room tempRoomPreference=Room;
         
        while(!(userRoomView.toLowerCase().equals("economy") || userRoomView.toLowerCase().equals("deluxe") || userRoomView.toLowerCase().equals("executive") || 
             userRoomView.toLowerCase().startsWith("n"))) {
             
             System.out.println("Please enter Economy, Deluxe, or Executive. Or enter no to exit");
             userRoomView=input.next();
         }
         
      
        if(userRoomView.toLowerCase().equals("economy")) {
            for(int i = 0; i < hotel1.size(); i++) {
               if(hotel1.getRoom(i).getRoomAvailability()==true && hotel1.getRoom(i).getRoomType().equals("economy")) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  tempRoomPreference=EconomyCompare;
                  roomNumber="Room "+ i;
                  
                  i=hotel1.size();
                }
            }
        }
        
        if(userRoomView.toLowerCase().equals("deluxe")) {
            for(int i = 0; i < hotel1.size(); i++) {
               if(hotel1.getRoom(i).getRoomAvailability()==true && hotel1.getRoom(i).getRoomType().equals("deluxe")) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  tempRoomPreference=DeluxeCompare;
                  roomNumber="Room "+ i;
           
                  i=hotel1.size();
                }
            }
        }
        
         else if(userRoomView.toLowerCase().equals("executive")) {
            for(int i = 0; i < hotel1.size(); i++) {
               if(hotel1.getRoom(i).getRoomAvailability()==true && hotel1.getRoom(i).getRoomType().equals("executive")) {
                  hotel1.getRoom(i).setRoomAvailability(false);
                  
                  System.out.println("We've reserved room " + (i) + " for you.");
                  reservedRoom=hotel1.getRoom(i);
                  tempRoomPreference=ExecutiveCompare;
                  roomNumber="Room "+ i;
     
                  i=hotel1.size();
                }
            }
        }
         else if(userRoomView.toLowerCase().startsWith("n")){
            HotelMain.hotelGreeting();
            System.exit(0);
         }
        
        System.out.println("How many nights are you staying?");
          String testDurationOfStay="";
          durationOfStay =0;

        
          while(testDurationOfStay !="!PASS!"){

            if(input.hasNextInt()){
                  durationOfStay= input.nextInt();
                  
                  if((durationOfStay > 0) && (durationOfStay < 160)){
                     testDurationOfStay="!PASS!";
                  }
                  else{
                     System.out.println("Please enter a valid number of nights.");
                  }
            }
            else{
               System.out.println("Please enter a valid number of nights.");
               testDurationOfStay  = input.next();
            }
            
         }


        
        System.out.println("Thanks for choosing Mamou Hotels.");
      
       System.out.println("You're room is reserved.You are in " + roomNumber + ". To finalize your payment of $" + hotel1.calculateCost(reservedRoom,durationOfStay,NewCustomer) +" please enter yes. To cancel, enter no.");
       String paymentString = input.next();
       boolean payment=false;
         
       while(!(paymentString.toLowerCase().startsWith("y") || paymentString.toLowerCase().startsWith("n"))){
            System.out.println("Please enter yes or no.");
            paymentString = input.next();
         }
         
         if(paymentString.toLowerCase().startsWith("y")) {
            payment=true;
            hotel1.makePayment(payment,reservedRoom);
            hotel1.printReceipt(reservedRoom,durationOfStay,NewCustomer,roomNumber);

         }
         
         if(paymentString.toLowerCase().startsWith("n")) {
            payment=false;
            hotel1.makePayment(payment,reservedRoom);
            validateInfo(input, durationOfStay,tempRoomPreference,memberList1,NewCustomer);

          }
    
     }       
}
