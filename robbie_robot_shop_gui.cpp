#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cstdlib>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/fl_ask.H>


using namespace std;

class Customer {
  public:
    Customer(string c_name, string c_phone_number, string c_email_address, int c_customer_number) { name = c_name; customer_number = c_customer_number; phone_number = c_phone_number; email_address = c_email_address; }
    Customer() { }
    string to_string() {
      string customer = "Name: " + name + ",  " + "Phone Number: " + phone_number + ",  " + "Email Address: " + email_address + ",  " + "\n    Customer Number: " + std::to_string(customer_number);
      return customer;
    }
    string name;
    int customer_number;
    string phone_number;
    string email_address;
};

class Sales_associate {
  public:
    Sales_associate(string s_name, int s_employee_number) : name(s_name), employee_number(s_employee_number) { }
    Sales_associate() { }
    string to_string() {
      string sa = "Name: " + name + ",  " + "Employee Number: " + std::to_string(employee_number);
      return sa;
    }
    string name;
    int employee_number;
};

class Robot_part {
  public:
    Robot_part(string p_name, string p_model_number, double p_cost, string p_description, double p_weight) { name = p_name; model_number = p_model_number; cost = p_cost; description = p_description; weight = p_weight; }
    Robot_part() { }
    string to_string() {
      string part = "Name: " + name + ",  " + "Type: " + type + ",  " + "Model Number: " + model_number + ",  " + "\n    Cost: $" + std::to_string(cost)+ ",  " + "Description: " + description + ",  " + "Weight(kg): " + std::to_string(weight) + " kg\n";
      return part;
    }
    string name;
    string type;
    string model_number;
    double cost;
    string description;
    double weight;
    string image_filename;
};

class Arm : public Robot_part {
  public:
    Arm(string p_name, string p_model_number, double p_cost, string p_description, double p_weight, double p_max_power, string p_type) { name = p_name; model_number = p_model_number; cost = p_cost; description = p_description; weight = p_weight; max_power = p_max_power; type = p_type; }
  private:
    double max_power;
};

class Battery : public Robot_part {
  public:
    Battery(string p_name, string p_model_number, double p_cost, string p_description, double p_weight, double p_power_available, double p_max_energy, string p_type) { name = p_name; model_number = p_model_number; cost = p_cost; description = p_description; weight = p_weight; power_available = p_power_available; max_energy = p_max_energy; type = p_type; }
  private:
    double power_available;
    double max_energy;
};

class Torso : public Robot_part {
  public:
    Torso(string p_name, string p_model_number, double p_cost, string p_description, double p_weight, int p_battery_compartments, int p_max_arms, string p_type) { name = p_name; model_number = p_model_number; cost = p_cost; description = p_description; weight = p_weight; battery_compartments = p_battery_compartments; max_arms = p_max_arms; type = p_type; }
  private:
    int battery_compartments;
    int max_arms;
};

class Locomotor : public Robot_part {
  public:
    Locomotor(string p_name, string p_model_number, double p_cost, string p_description, double p_weight, double p_max_power, string p_type) { name = p_name; model_number = p_model_number; cost = p_cost; description = p_description; weight = p_weight; max_power = p_max_power; type = p_type; }
  private:
    double max_power;
};

class Head : public Robot_part {
  public:
    Head(string p_name, string p_model_number, double p_cost, string p_description, double p_weight, double p_power, string p_type) { name = p_name; model_number = p_model_number; cost = p_cost; description = p_description; weight = p_weight; power = p_power; type = p_type; }
  private:
    double power;
};

class Robot_model {
  public:
    Robot_model(string m_name, int m_model_number, Robot_part m_torso, Robot_part m_head, Robot_part m_locomotor, Robot_part m_arm1, Robot_part m_arm2, Robot_part m_battery1, double m_num_batt) { name = m_name; model_number = m_model_number; arm1 = m_arm1; arm2 = m_arm2; battery1 = m_battery1; num_batt = m_num_batt; }
    Robot_model(string m_name, int m_model_number, Robot_part m_torso, Robot_part m_head, Robot_part m_locomotor, Robot_part m_arm1, Robot_part m_arm2, Robot_part m_battery1, Robot_part m_battery2, double m_num_batt) { name = m_name; model_number = m_model_number; arm1 = m_arm1; arm2 = m_arm2; battery1 = m_battery1; battery2 = m_battery2; num_batt = m_num_batt; }
    Robot_model(string m_name, int m_model_number, Robot_part m_torso, Robot_part m_head, Robot_part m_locomotor, Robot_part m_arm1, Robot_part m_arm2, Robot_part m_battery1, Robot_part m_battery2, Robot_part m_battery3, double m_num_batt) { name = m_name; model_number = m_model_number; arm1 = m_arm1; arm2 = m_arm2; battery1 = m_battery1; battery2 = m_battery2; battery3 = m_battery3; num_batt = m_num_batt; }
    Robot_model() { }
    string to_string() {
      string model = "Name: " + name + ",  " + "Model Number: " + std::to_string(model_number) + ",  " + "Torso: " + torso.name + ",  " + "\n    Head: " + head.name + ",  " + "Locomotor: " + locomotor.name + ",  " + "Arm One: " + arm1.name + ",  " + "\n    Arm Two: " + arm2.name + ",  " + "Battery One: " + battery1.name + "  " + "Battery Two: " + battery2.name + ",  " + "\n    Battery Three: " + battery3.name + ",  " + "Cost: $" + std::to_string(modCost) + ",  " + "Max Speed: " + std::to_string(max_speed()) + " MPH\n"/* + "  " + "Max Battery Life: " + std::to_string(max_battery_life()) + " hrs"*/;
      return model;
    }
    double cost();
    double max_speed();
    double max_battery_life();
    double tot_weight();

    string name;
    int model_number;
    double num_batt;
    double modCost;
    Robot_part torso;
    Robot_part head;
    Robot_part locomotor;
    Robot_part arm1;
    Robot_part arm2;
    Robot_part battery1;
    Robot_part battery2;
    Robot_part battery3;
};
double Robot_model::cost() {
  double cost = torso.cost + head.cost + locomotor.cost + arm1.cost + arm2.cost + battery1.cost + battery2.cost + battery3.cost;
  modCost = cost;
  return cost;
}
double Robot_model::max_speed() {
  double max_speed = 12 * ((locomotor.weight*5)/(torso.weight+head.weight+locomotor.weight+arm1.weight+arm2.weight+battery1.weight+battery2.weight+battery3.weight));
  return max_speed;
}

double Robot_model::max_battery_life() {
//  double max_battery_life = (num_batt*1000)/(head.power+(0.4*(arm1.max_power + arm2.max_power)+(0.15*locomotor.max_power));
//  return max_battery_life;
}

double Robot_model::tot_weight() {
}

class Order {
  public:
    Order(int o_order_number, string o_date, Customer o_customer, Sales_associate o_sales_associate, Robot_model o_robot_model) { order_number = o_order_number; date = o_date; customer = o_customer; sales_associate = o_sales_associate; robot_model = o_robot_model; }
    string to_string() {
      string order = "Order Number: " + std::to_string(order_number) + ",  " + "Date: " + date + ",  " + "Customer: " + customer.name + ",  " + "\n    Sales Associate: " + sales_associate.name + ",  " + "Robot Model: " + robot_model.name + ",  " + "Raw Price: $" + std::to_string(cost) + ",  " + "\n    Sales Price: $" + std::to_string(extPrice);
      return order;
    }
    double robot_cost();
    double extended_price();
  private:
    int order_number;
    double cost;
    double extPrice;
    string date;
    Customer customer;
    Sales_associate sales_associate;
    Robot_model robot_model;
    int status;
};

double Order::robot_cost() {
  double orderCost = robot_model.modCost;
  return orderCost;
}

double Order::extended_price() {
  double tax = robot_model.modCost * 8.25;
  double shipping = (robot_model.tot_weight() / 45) * 15;
  double price = robot_model.modCost + tax + shipping;
  extPrice = price;
  return price;
}

// /////// //
// S H O P //
// /////// //

class Shop {
  public:
    void create_new_robot_part(Robot_part part);
    void create_new_robot_model(Robot_model model);
    void create_new_customer(Customer cust);
    void create_new_sales_associate(Sales_associate sa);
    void create_new_order(Order order);
    void save(string filename);
    void open(string filename);

    string robot_part_to_string(int part_index);
    string robot_model_to_string(int model_index);
    string customer_to_string(int customer_index);
    string sales_associate_to_string(int sa_index);
    string order_to_string(int order_index);

    int number_of_robot_parts();
    int number_of_robot_models();
    int number_of_customers();
    int number_of_sales_associates();
    int number_of_orders();

    vector<Robot_part> robot_parts;
    vector<Order> orders;
    vector<Robot_model> robot_models;
    vector<Customer> customers;
    vector<Sales_associate> sales_associates;

    friend istream& operator >> (istream& in, Shop& shop);
    friend ostream& operator << (ostream& out, const Shop& shop);
};

istream& operator >> (istream& in, Shop& shop) {
  in >> shop.robot_parts;
  in >> shop.orders;
  in >> shop.robot_models;
  in >> shop.customers;
  in >> shop.sales_associates;
  return in;
}

istream& operator << (ostream& out, const Shop& shop) {
  
}

void Shop::create_new_robot_part(Robot_part part) {
  robot_parts.push_back(part);
}

void Shop::create_new_robot_model(Robot_model model) {
  robot_models.push_back(model);
}

void Shop::create_new_customer(Customer cust) {
  customers.push_back(cust);
}

void Shop::create_new_sales_associate(Sales_associate sa) {
  sales_associates.push_back(sa);
}

void Shop::create_new_order(Order order) {
  orders.push_back(order);
}

void Shop::save(string filename) {
//  friend istream& operator>>(istream& in, Shop& shop);
}

void Shop::open(string filename) {
}

string Shop::robot_part_to_string(int part_index) {
  return robot_parts[part_index].to_string();
}

string Shop::robot_model_to_string(int model_index) {
  return robot_models[model_index].to_string();
}

string Shop::customer_to_string(int customer_index) {
  return customers[customer_index].to_string();
}

string Shop::sales_associate_to_string(int sa_index) {
  return sales_associates[sa_index].to_string();
}

string Shop::order_to_string(int order_index) {
  return orders[order_index].to_string();
}

int Shop::number_of_robot_parts() {
  return robot_parts.size();
}

int Shop::number_of_robot_models() {
  return robot_models.size();
}

int Shop::number_of_customers() {
  return customers.size();
}

int Shop::number_of_sales_associates() {
  return sales_associates.size();
}

int Shop::number_of_orders() {
  return orders.size();
}

// /////// //
// V I E W //
// /////// //

class View {
  public:
    View(Shop& sp) : shop(sp) {}
    string get_menu();
    string get_parts_list();
    string get_models_list();
    string get_orders_list();
    string get_customers_list();
    string get_sales_associates_list();
  private:
    Shop& shop;
};

string View::get_menu() {
  string menu = R"(
=======================
C1325 Robbie Robot Shop
=======================

File
----
(1) Save Shop
(2) Load Shop

Create
------
(3) Robot Part
(4) Robot Model
(5) Customer
(6) Sales Associate
(7) Order

View
----
(8) Robot Parts
(9) Robot Models
(10) Customers
(11) Sales Associates
(12) Orders

Help
----
(13) Help
(14) Exit
)";
    return menu;
}

string View::get_parts_list() {
  string list = R"(
-------------------
List of Robot Parts
-------------------
)";
  for (int i=0; i<shop.number_of_robot_parts(); ++i) {
    list += std::to_string(i) + ") " + shop.robot_part_to_string(i) + '\n';
  }
  return list;
}

string View::get_models_list() {
  string list = R"(
--------------------
List of Robot Models
--------------------
)";
  for (int i=0; i<shop.number_of_robot_models(); ++i) {
    list += std::to_string(i) + ") " + shop.robot_model_to_string(i) + '\n';
  }
  return list;
}

string View::get_orders_list() {
  string list = R"(
--------------
List of Orders
--------------
)";
  for (int i=0; i<shop.number_of_orders(); ++i) {
    list += std::to_string(i) + ") " + shop.order_to_string(i) + '\n';
  }
  return list;
}

string View::get_customers_list() {
  string list = R"(
-----------------
List of Customers
-----------------
)";
  for (int i=0; i<shop.number_of_customers(); ++i) {
    list += std::to_string(i) + ") " + shop.customer_to_string(i) + '\n';
  }
  return list;
}

string View::get_sales_associates_list() {
  string list = R"(
------------------------
List of Sales Associates
------------------------
)";
  for (int i=0; i<shop.number_of_sales_associates(); ++i) {
    list += std::to_string(i) + ") " + shop.sales_associate_to_string(i) + '\n';
  }
  return list;
}

// /////// //
// M A I N //
// /////// //

Shop shop;
View view{shop};

int get_int(string title, string prompt, int max_int) {
  string error = "Please enter an integer between 0 and " + std::to_string(max_int);
  int result;
  while(true) {
    fl_message_title(title.c_str());
    result = atoi(fl_input(prompt.c_str(), 0));
    if(0 <= result && result <= max_int) break;
    fl_message_title("Invalid input");
    fl_message(error.c_str());
  }
  return result;
}

double get_double(string title, string prompt, double max_double) {
  string error = "Please enter an number between 0 and " + std::to_string(max_double);
  double result;
  while(true) {
    fl_message_title(title.c_str());
    result = atoi(fl_input(prompt.c_str(), 0));
    if(0 <= result && result <= max_double) break;
    fl_message_title("Invalid input");
    fl_message(error.c_str());
  }
  return result;
}

string get_string(string title, string prompt) {
  fl_message_title(title.c_str());
  string result{fl_input(prompt.c_str(), 0)};
  return result;
}

Fl_Window *wind;
Fl_Menu_Bar *menubar;

void CloseCB(Fl_Widget* w, void* p) {
  wind->hide();
  exit(0);
}

void SaveCB(Fl_Widget* w, void* p) {
  
}



void LoadCB(Fl_Widget* w, void* p) {

}

void CreateOrderCB(Fl_Widget* w, void* p) {
  int order_number, customer, sales_associate, robot_model;
    string date;

    order_number = get_int("Order Number", "Order Number? ", 1000000);

    date = get_string("Date", "Date? ");

    string custList = view.get_customers_list();
    customer = get_int("Customer", custList + "\nCustomer? ", 1000000);
    Customer c_customer = shop.customers[customer];

    string saList = view.get_sales_associates_list();
    sales_associate = get_int("Sales Associate", saList + "\nSales Associate? ", 1000000);
    Sales_associate sa_sales_associate = shop.sales_associates[sales_associate];

    string modList = view.get_models_list();
    robot_model = get_int("Robot Model", modList + "\nRobot Model? ", 1000000);
    Robot_model m_robot_model = shop.robot_models[robot_model];

    shop.create_new_order(Order(order_number, date, c_customer, sa_sales_associate, m_robot_model));
}

void CreateCustomerCB(Fl_Widget* w, void* p) {
  string name, phone_number, email_address;
    int customer_number;

    name = get_string("Name", "Name? ");
    phone_number = get_string("Phone Number", "Phone Number? ");
    email_address = get_string("Email Address", "Email Address? ");
    customer_number = get_int("Customer Number", "Customer Number? ", 1000000);

    shop.create_new_customer(Customer(name, phone_number, email_address, customer_number));
}

void CreateSalesAssociateCB(Fl_Widget* w, void* p) {
  string name;
    int employee_number;

    name = get_string("Name", "Name? ");
   employee_number = get_int("Employee Number", "Employee Number? ", 1000000);

    shop.create_new_sales_associate(Sales_associate(name, employee_number));
}

void CreateModelCB(Fl_Widget* w, void* p) {
	string name, list;
	int torso, head, locomotor, arm1, arm2, battery1, battery2, battery3, model_number, num_batt;
        
	name = get_string("Name", "Name? "); 
	model_number = get_int("Model Number", "Model Number? ", 1000000);

	list = view.get_parts_list();

	torso = get_int("Torso", list + "\nTorso? ", 1000);
	Robot_part p_torso = shop.robot_parts[torso];

	head = get_int("Head", list + "\nHead? ", 1000);
	Robot_part p_head = shop.robot_parts[head];

	locomotor = get_int("Locomotor", list + "\nLocomotor? ", 1000);
	Robot_part p_locomotor = shop.robot_parts[locomotor];

	arm1 = get_int("Arm One", list + "\nArm One? ", 1000);
	Robot_part p_arm1 = shop.robot_parts[arm1];

	arm2 = get_int("Arm Two", list + "\nArm Two? ", 1000);
	Robot_part p_arm2 = shop.robot_parts[arm2];

	num_batt = get_int("Number of Batteries", "Number of Batteries? (1-3)", 3);

	switch(num_batt) {
	  case 1: {
	    battery1 = get_int("Battery One", list + "\nBattery One? ", 1000);
	    Robot_part p_battery1 = shop.robot_parts[battery1];
	    shop.create_new_robot_model(Robot_model(name, model_number, p_torso, p_head, p_locomotor, p_arm1, p_arm2, p_battery1, (double)num_batt));
	    break;
	  }
	  case 2: {
	    battery1 = get_int("Battery One", list + "\nBattery One? ", 1000);
	    Robot_part p_battery1 = shop.robot_parts[battery1];
	    battery2 = get_int("Battery Two", list + "\nBattery Two? ", 1000);
	    Robot_part p_battery2 = shop.robot_parts[battery2];
	    shop.create_new_robot_model(Robot_model(name, model_number, p_torso, p_head, p_locomotor, p_arm1, p_arm2, p_battery1, p_battery2, (double)num_batt));
	    break;
	  }
	  case 3: {
	    battery1 = get_int("Battery One", list + "\nBattery One? ", 1000);
	    Robot_part p_battery1 = shop.robot_parts[battery1];
	    battery2 = get_int("Battery Two", list + "\nBattery Two? ", 1000);
	    Robot_part p_battery2 = shop.robot_parts[battery2];
	    battery3 = get_int("Battery Three", list + "\nBattery Three? ", 1000);
	    Robot_part p_battery3 = shop.robot_parts[battery3];
	    shop.create_new_robot_model(Robot_model(name, model_number, p_torso, p_head, p_locomotor, p_arm1, p_arm2, p_battery1, p_battery2, p_battery3, (double)num_batt));
	    break;
	  }
	  default: {
	    break;
	  }
	}
}

void CreatePartCB(Fl_Widget* w, void* p) {
  string name, model_number, description, strType;
    double cost, max_power, power_available, max_energy, power, battery_compartments, max_arms, weight;
    int type;
    Robot_part part;

    type = get_int("Title", "\n0) Arm\n1) Battery\n2) Torso\n3) Locomotor\n4) Head\n\nTitle?", 4);

    name = get_string("Name", "Name? ");

    model_number = get_string("Model Number", "Model Number? ");

    description = get_string("Description", "Description? ");

    weight = get_double("Weight", "Weight(kg)? ", 100000);

    cost = get_double("Cost", "Cost? ", 1000000);

    switch(type) {
      case 0:
        max_power = get_double("Max Power", "Max Power? ", 100000);
	strType = "arm";
        shop.create_new_robot_part(Arm(name, model_number, cost, description, weight, max_power, strType));        
        break;
      case 1:
        power_available = get_double("Power Available", "Power Available? ", 100000);
        max_energy = get_double("Max Energy", "Max Energy? ", 100000);
	strType = "battery";
        shop.create_new_robot_part(Battery(name, model_number, cost, description, weight, power_available, max_energy, strType));
        break;
      case 2:
        battery_compartments = get_double("Battery Compartments", "Number of Battery Compartments? ", 3);
        max_arms = get_double("Max Arms", "Max Number of Arms? ", 2);
	strType = "torso";
        shop.create_new_robot_part(Torso(name, model_number, cost, description, weight, battery_compartments, max_arms, strType));
        break;
      case 3:
        max_power = get_double("Max Power", "Max Power? ", 100000);
	strType = "locomotor";
        shop.create_new_robot_part(Locomotor(name, model_number, cost, description, weight, max_power, strType));
        break;
      case 4:
        power = get_double("Power", "Power? ", 100000);
	strType = "head";
        shop.create_new_robot_part(Head(name, model_number, cost, description, weight, power, strType));
        break;
      default:
        break;
    }
}

void ViewOrdersCB(Fl_Widget* w, void* p) {
  string list = view.get_orders_list();
  fl_message_title("List of Orders");
  fl_message(list.c_str());
}

void ViewCustomersCB(Fl_Widget* w, void* p) {
  string list = view.get_customers_list();
  fl_message_title("List of Customers");
  fl_message(list.c_str());
}

void ViewSalesAssociatesCB(Fl_Widget* w, void* p) {
  string list = view.get_sales_associates_list();
  fl_message_title("List of Sales Associates");
  fl_message(list.c_str());
}

void ViewModelsCB(Fl_Widget* w, void* p) {
  string list = view.get_models_list();
  fl_message_title("List of Robot Models");
  fl_message(list.c_str());
}

void ViewPartsCB(Fl_Widget* w, void* p) {
  string list = view.get_parts_list();
  fl_message_title("List of Robot Parts");
  fl_message(list.c_str());
}

void HelpCB(Fl_Widget* w, void* p) {
  string help1 = R"(
===============
Brief User Manual: Page 1
===============

File > Save : Saves a Robot Shop to a file
File > Load : Loads a Robot Shop from a file
File > Exit : Exits the Robot Shop
---------------------------------------------------------------
Create > Order : Allows a sales associate to order robot models and presents a bill of sale 
listing the order number, date of sale, customer name, robot ordered and price 
Create > Customer : Allows a beloved customer to be added to the customer list
Create > Sales Associate : Allows a sales associate to be added to the sales associates list
Create > Robot Model : Allows the product manager to define a robot model with a head, torso, 
locomotor, up to two arms, and up to three batteries
Create > Robot Component : Allow the product manager to define a robot component of type head, 
torso, locomotor, arm or battery
)";
  string help2 = R"(
===============
Brief User Manual: Page 2
===============

View > Orders : View a list of all orders placed by the sales associates
View > Customers : View a list of all beloved customers of the Robbie Robot Shop
View > Sales Associates : View a list of all the sales associates of the Robbie Robot Shop
View > Robot Models : View a list of all the robot models defined by the product manager
View > Robot Parts : View a list of all the robot components defined by the product manager
---------------------------------------------------------------
Help > About : View a brief user manual describing the basic functionality of each Robbie Robot Shop feature
)";
  fl_message_title("Brief User Manual: Page 1");
  fl_message(help1.c_str());
  fl_message_title("Brief User Manual: Page 2");
  fl_message(help2.c_str());
}

Fl_Menu_Item menuitems[] = {
  { "&File", 0, 0, 0, FL_SUBMENU },
    { "&Save", FL_ALT + 's', (Fl_Callback *)SaveCB },
    { "&Load", FL_ALT + 'l', (Fl_Callback *)LoadCB },
    { "&Exit", FL_ALT + 'q', (Fl_Callback *)CloseCB },
    { 0 },
  { "&Create", 0, 0, 0, FL_SUBMENU },
    { "&Order", FL_ALT + 'o', (Fl_Callback *)CreateOrderCB },
    { "&Customer", FL_ALT + 'c', (Fl_Callback *)CreateCustomerCB },
    { "&Sales Associate", FL_ALT + 'a', (Fl_Callback *)CreateSalesAssociateCB },
    { "&Robot Model", FL_ALT + 'm', (Fl_Callback *)CreateModelCB },
    { "&Robot Component", FL_ALT + 'p', (Fl_Callback *)CreatePartCB },
    { 0 },
  { "&View", 0, 0, 0, FL_SUBMENU },
    { "Orders", 0, (Fl_Callback *)ViewOrdersCB },
    { "Customers", 0, (Fl_Callback *)ViewCustomersCB },
    { "Sale Associates", 0, (Fl_Callback *)ViewSalesAssociatesCB },
    { "Robot Models", 0, (Fl_Callback *)ViewModelsCB },
    { "Robot Parts", 0, (Fl_Callback *)ViewPartsCB },
    { 0 },
  { "&Help", 0, 0, 0, FL_SUBMENU },
    { "About", FL_ALT + 'h', (Fl_Callback *)HelpCB },
    { 0 },
  { 0 }
};

int main() {
  fl_register_images();
  Fl_Window win(1,1);
  win.show();

  wind = new Fl_Window{640, 480, "Robbie Robot Shop"};
  menubar = new Fl_Menu_Bar(0, 0, 640, 30);
  menubar->menu(menuitems);

  wind->end();
  wind->show();
  return(Fl::run());
}
