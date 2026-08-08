#include <iostream>
#include <string>
using namespace std;

// ============================================================

//           PEER-TO-PEER SELF STORAGE PROGRAM

// ============================================================


// ============================================================
// USER CLASS
// ============================================================

class User {
private:
    string email;
    string password;
    string firstName;
    string lastName;
    string phoneNum;
    bool isVerified;

    // PRIVATE CLASS
    class LoginInfo {
    private:
        string username;

    public:
        LoginInfo(string name) {
            username = name;
        }

        string getUsername() {
            return username;
        }
    };

public:

    // --------------------------------------------------------
    // DEFAULT CONSTRUCTOR
    // --------------------------------------------------------
    User() {
        email = "";
        password = "";
        firstName = "";
        lastName = "";
        phoneNum = "";
        isVerified = false;
    }

    // --------------------------------------------------------
    // CONSTRUCTOR WITH PARAMETERS
    // --------------------------------------------------------
    User(string setEmail, string setPassword,
         string setFirstName, string setLastName,
         string setPhoneNum) {

        email = setEmail;
        password = setPassword;
        firstName = setFirstName;
        lastName = setLastName;
        phoneNum = setPhoneNum;
        isVerified = false;
    }

    // --------------------------------------------------------
    // SETTERS
    // --------------------------------------------------------
    void setEmail(string userEmail) {
        email = userEmail;
    }

    void setPassword(string userPassword) {
        password = userPassword;
    }

    void setFirstName(string userFirstName) {
        firstName = userFirstName;
    }

    void setLastName(string userLastName) {
        lastName = userLastName;
    }

    void setPhoneNum(string userPhoneNum) {
        phoneNum = userPhoneNum;
    }

    void setVerified(bool verified) {
        isVerified = verified;
    }

    // --------------------------------------------------------
    // GETTERS
    // --------------------------------------------------------
    string getEmail() {
        return email;
    }

    string getPassword() {
        return password;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getPhoneNum() {
        return phoneNum;
    }

    bool getVerified() {
        return isVerified;
    }

    // --------------------------------------------------------
    // FUNCTION OVERLOADING
    // --------------------------------------------------------

    // Displays the user's name.
    void displayUser() {
        cout << firstName << " " << lastName << endl;
    }

    // Displays the user's name and contact information.
    void displayUser(bool showContactInfo) {
        cout << firstName << " " << lastName << endl;

        if (showContactInfo) {
            cout << "Email: " << email << endl;
            cout << "Phone: " << phoneNum << endl;
        }
    }

    // --------------------------------------------------------
    // FRIEND FUNCTION
    // --------------------------------------------------------
    friend void verifyUser(User &user);

    // --------------------------------------------------------
    // FRIEND CLASS
    // --------------------------------------------------------
    friend class UserManager;
};


// ============================================================
// FRIEND FUNCTION
// ============================================================

void verifyUser(User &user) {
    user.isVerified = true;

    cout << "The host of the storage space is: \n"
         << user.firstName
         << " (credentials verified)"
         << endl;
}


// ============================================================
// FRIEND CLASS
// ============================================================

class UserManager {
public:

    void showPrivateUserInfo(User &user) {
        cout << "Private user email: "
             << user.email
             << endl;
    }
};


// ============================================================
// BASE CLASS: LISTING
// ============================================================

class Listing {
protected:

    int listingID;
    string listingType;
    string listingCity;
    string listingState;
    string zipcode;
    double listingPrice;

    // Pointer to the owner of this listing.
    User* owner;

    // True if the listing has been booked.
    bool booked;

public:

    // --------------------------------------------------------
    // CONSTRUCTOR
    // --------------------------------------------------------
    Listing(int ID,
            string type,
            string city,
            string state,
            string zip,
            double price,
            User* listingOwner,
            bool isBooked = false) {

        listingID = ID;
        listingType = type;
        listingCity = city;
        listingState = state;
        zipcode = zip;
        listingPrice = price;
        owner = listingOwner;
        booked = isBooked;
    }

    // --------------------------------------------------------
    // SETTERS
    // --------------------------------------------------------
    void setListingID(int id) {
        listingID = id;
    }

    void setListingType(string type) {
        listingType = type;
    }

    void setCity(string city) {
        listingCity = city;
    }

    void setState(string state) {
        listingState = state;
    }

    void setZipcode(string zip) {
        zipcode = zip;
    }

    void setListingPrice(double price) {
        listingPrice = price;
    }

    void setOwner(User* listingOwner) {
        owner = listingOwner;
    }

    void setBooked(bool isBooked) {
        booked = isBooked;
    }

    // --------------------------------------------------------
    // GETTERS
    // --------------------------------------------------------
    int getListingID() {
        return listingID;
    }

    string getListingType() {
        return listingType;
    }

    string getCity() {
        return listingCity;
    }

    string getState() {
        return listingState;
    }

    string getZipcode() {
        return zipcode;
    }

    double getListingPrice() {
        return listingPrice;
    }

    User* getOwner() {
        return owner;
    }

    bool isBooked() {
        return booked;
    }

    // --------------------------------------------------------
    // DISPLAY OWNER INFORMATION
    // --------------------------------------------------------
    void displayOwner() {

        if (owner != nullptr) {
            cout << "Owner: "
                 << owner->getFirstName()
                 << " "
                 << owner->getLastName()
                 << endl;

            cout << "Owner Email: "
                 << owner->getEmail()
                 << endl;

            cout << "Owner Phone: "
                 << owner->getPhoneNum()
                 << endl;
        }
        else {
            cout << "Owner: Not Assigned" << endl;
        }
    }

    // --------------------------------------------------------
    // POLYMORPHISM
    // --------------------------------------------------------
    virtual void displayListing() {

        cout << "Listing ID: "
             << listingID
             << endl;

        cout << "Type: "
             << listingType
             << endl;

        cout << "Location: "
             << listingCity
             << ", "
             << listingState
             << " "
             << zipcode
             << endl;

        cout << "Price: $"
             << listingPrice
             << " per month"
             << endl;

        displayOwner();

        if (booked) {
            cout << "Status: BOOKED" << endl;
        }
        else {
            cout << "Status: AVAILABLE" << endl;
        }
    }

    // --------------------------------------------------------
    // VIRTUAL DESTRUCTOR
    // --------------------------------------------------------
    virtual ~Listing() {}
};


// ============================================================
// CHILD CLASS: GARAGE LISTING
// ============================================================

class GarageListing : public Listing {

private:
    double garageSize;
    bool climateControlled;

public:

    // --------------------------------------------------------
    // CONSTRUCTOR
    // --------------------------------------------------------
    GarageListing(int ID,
                  string city,
                  string state,
                  string zip,
                  double price,
                  double size,
                  bool climate,
                  User* listingOwner,
                  bool isBooked = false)

        : Listing(ID,
                   "Garage",
                   city,
                   state,
                   zip,
                   price,
                   listingOwner,
                   isBooked) {

        garageSize = size;
        climateControlled = climate;
    }

    // --------------------------------------------------------
    // POLYMORPHISM
    // --------------------------------------------------------
    void displayListing() override {

        cout << "----- GARAGE LISTING -----" << endl;

        cout << "Listing ID: "
             << listingID
             << endl;

        cout << "Location: "
             << listingCity
             << ", "
             << listingState
             << " "
             << zipcode
             << endl;

        cout << "Price: $"
             << listingPrice
             << " per month"
             << endl;

        cout << "Garage Size: "
             << garageSize
             << " sq ft"
             << endl;

        if (climateControlled) {
            cout << "Climate Controlled: Yes" << endl;
        }
        else {
            cout << "Climate Controlled: No" << endl;
        }

        displayOwner();

        if (booked) {
            cout << "Status: BOOKED" << endl;
        }
        else {
            cout << "Status: AVAILABLE" << endl;
        }
    }
};


// ============================================================
// CHILD CLASS: DRIVEWAY LISTING
// ============================================================

class DrivewayListing : public Listing {

private:
    int vehicleSpaces;

public:

    // --------------------------------------------------------
    // CONSTRUCTOR
    // --------------------------------------------------------
    DrivewayListing(int ID,
                    string city,
                    string state,
                    string zip,
                    double price,
                    int spaces,
                    User* listingOwner,
                    bool isBooked = false)

        : Listing(ID,
                   "Driveway",
                   city,
                   state,
                   zip,
                   price,
                   listingOwner,
                   isBooked) {

        vehicleSpaces = spaces;
    }

    // --------------------------------------------------------
    // POLYMORPHISM
    // --------------------------------------------------------
    void displayListing() override {

        cout << "----- DRIVEWAY LISTING -----" << endl;

        cout << "Listing ID: "
             << listingID
             << endl;

        cout << "Location: "
             << listingCity
             << ", "
             << listingState
             << " "
             << zipcode
             << endl;

        cout << "Price: $"
             << listingPrice
             << " per month"
             << endl;

        cout << "Vehicle Spaces: "
             << vehicleSpaces
             << endl;

        displayOwner();

        if (booked) {
            cout << "Status: BOOKED" << endl;
        }
        else {
            cout << "Status: AVAILABLE" << endl;
        }
    }
};


// ============================================================
// TEMPLATE FUNCTION
// ============================================================

// This template allows the same function to work with
// different data types.
template <typename T>
void showValue(T value) {
    cout << "Value: " << value << endl;
}


// ============================================================
// RECURSIVE FUNCTION
// ============================================================

// This recursive function displays listings based on their
// booking status.
void displayListingsRecursive(
    Listing* listings[],
    int index,
    int size,
    bool showBooked) {

    // --------------------------------------------------------
    // BASE CASE
    // --------------------------------------------------------
    if (index >= size) {
        return;
    }

    // --------------------------------------------------------
    // DISPLAY ONLY LISTINGS THAT MATCH THE REQUESTED STATUS
    // --------------------------------------------------------
    if (listings[index] != nullptr &&
        listings[index]->isBooked() == showBooked) {

        listings[index]->displayListing();
        cout << endl;
    }

    // --------------------------------------------------------
    // RECURSIVE CALL
    // --------------------------------------------------------
    displayListingsRecursive(
        listings,
        index + 1,
        size,
        showBooked
    );
}


// ============================================================
// MAIN PROGRAM
// ============================================================

int main() {
    // --------------------------------------------------------
    // CREATE USERS
    // --------------------------------------------------------
    cout << "\n" << endl;
    cout << "Host and Client information for storage reservation " << endl;
    cout << "====================================================\n" << endl;

    // Renter looking to book space
    User renter(
        "renter@email.com",
        "password_john123",
        "John",
        "Smith",
        "555-111-2222"
    );

    // Original owner with current listing
    User owner(
        "owner@email.com",
        "password_sarah123",
        "Sarah",
        "Johnson",
        "555-333-4444"
    );

    // --------------------------------------------------------
    // ADDITIONAL OWNERS
    // --------------------------------------------------------
    
    // These owners will have booked listings
    User owner2(
        "michael@email.com",
        "password_michael456",
        "Michael",
        "Brown",
        "555-444-5555"
    );

    User owner3(
        "lisa@email.com",
        "password_lisa789",
        "Lisa",
        "Davis",
        "555-666-7777"
    );

    //cout << "\n" << endl;

    // --------------------------------------------------------
    // FRIEND FUNCTION: to retreive owner
    // --------------------------------------------------------
    verifyUser(owner);
    cout << endl;

    // --------------------------------------------------------
    // POINTER IMPLEMENTATION: to retreive owner information
    // --------------------------------------------------------
    User* pointerToOwner = &owner;

    cout << "The host contact information for the listing is:" << endl;
    cout << "Owner: "
         << pointerToOwner->getFirstName()
         << " "
         << pointerToOwner->getLastName()
         << endl;

    cout << "Email: "
         << pointerToOwner->getEmail()
         << endl;

    cout << "Phone: "
         << pointerToOwner->getPhoneNum()
         << endl;

    cout << "\n" << endl;

    // --------------------------------------------------------
    // OVERLOADED FUNCTION: to retrieve all client information
    // --------------------------------------------------------
    cout << "The client booking the storage space is:" << endl;

    renter.displayUser();

    cout << endl;

    cout << "The client's contact information is:" << endl;

    renter.displayUser(true);

    cout << endl;
    cout <<"\n" << endl;

    // --------------------------------------------------------
    // AVAILABLE LISTINGS
    // --------------------------------------------------------
    GarageListing garage1(
        101,
        "Detroit",
        "Michigan",
        "48201",
        150.00,
        400,
        true,
        &owner,
        false
    );

    GarageListing garage2(
        102,
        "Royal Oak",
        "Michigan",
        "48067",
        200.00,
        600,
        false,
        &owner,
        false
    );

    DrivewayListing driveway1(
        103,
        "Troy",
        "Michigan",
        "48083",
        75.00,
        2,
        &owner,
        false
    );

    // --------------------------------------------------------
    // BOOKED LISTING: Garage Listings
    // --------------------------------------------------------
    GarageListing garage3(
        104,
        "Warren",
        "Michigan",
        "48089",
        175.00,
        500,
        true,
        &owner2,
        true
    );

    // --------------------------------------------------------
    // BOOKED LISTING: Driveway Listings
    // --------------------------------------------------------
    DrivewayListing driveway2(
        105,
        "Southfield",
        "Michigan",
        "48075",
        90.00,
        3,
        &owner3,
        true
    );

    // --------------------------------------------------------
    // ARRAY: STORES MULTIPLE LISTINGS
    // --------------------------------------------------------

    // Listing pointers can point to different types of listings because 
    // Listing is the base class.
    Listing* listings[5];

    listings[0] = &garage1;
    listings[1] = &garage2;
    listings[2] = &driveway1;
    listings[3] = &garage3;
    listings[4] = &driveway2;

    // --------------------------------------------------------
    // FOR LOOP:  ALL AVAILABLE LISTINGS
    // --------------------------------------------------------
    cout << "ALL AVAILABLE STORAGE LISTINGS  " << endl;
    cout << "===============================" << endl;

    for (int i = 0; i < 5; i++) {

        // Only display listings that are NOT booked.
        if (!listings[i]->isBooked()) {

            // POLYMORPHISM:
            // The correct child class displayListing()
            // is called.
            listings[i]->displayListing();

            cout << endl;
        }
    }
    cout << "\n" << endl;

    // --------------------------------------------------------
    // RECURSION IMPLEMENTATION - BOOKED LISTINGS
    // --------------------------------------------------------
    cout << "BOOKED LISTINGS (currently not available)  " << endl;
    cout << "==========================================" << endl;

    // true means display only BOOKED listings.
    displayListingsRecursive(
        listings,
        0,
        5,
        true
    );

    // --------------------------------------------------------
    // END PROGRAM
    // --------------------------------------------------------
    cout << endl;
    cout << "Program Executed!" << endl;

    return 0;
}
