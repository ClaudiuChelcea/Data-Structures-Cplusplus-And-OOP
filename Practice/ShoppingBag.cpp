#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <assert.h>
#include <stdio.h>
#include <string.h>

// Product class
class Product {
private:
    std::string name;
    double price;
    int product_id;
    int num_products;

protected:
    static int products_nr;
    const std::string class_name{ "Product" };

public:
    // Constructors and destructor
    Product() = default;
    Product(std::string name = "", double price = 0, int product_id = -1, int num_products = 0)
        : name(name)
        , price(price)
        , product_id(product_id)
        , num_products(num_products)
    {
        products_nr++;
    }
    ~Product() = default;

    // Getters & Setters
    auto getName()
    {
        return name;
    }
    auto getPrice()
    {
        return price;
    }
    auto getID()
    {
        return product_id;
    }
    auto getNumProducts()
    {
        return num_products;
    }
    auto setName(std::string value)
    {
        name = value;
    }
    auto setPrice(double value)
    {
        price = value;
    }
    auto setID(int value)
    {
        product_id = value;
    }
    auto setNumProducts(int value)
    {
        num_products = value;
    }

    // Copy constructor
    Product(const Product& new_product)
    {
        this->name = new_product.name;
        this->price = new_product.price;
        this->product_id = new_product.product_id;
        this->num_products = new_product.num_products;
    }

    // Operators used for future sortings
    bool operator>(const Product& product)
    {
        return this->price * this->num_products > product.price * product.num_products;
    }

    bool operator==(const Product& product)
    {
        if (this->product_id == product.product_id && this->name == product.name && this->price == product.price && this->num_products == product.num_products)
            return true;
        return false;
    }

    bool operator<(const Product& product)
    {
        return this->price < product.price;
    }

    // Write product to text file
    void save_to_text(const char* file_name)
    {
        // Create and open file
        std::ofstream fout(file_name, std::ios::out | std::ios::app);

        // Write content
        fout << this->product_id << " " << this->name << " " << this->price << " " << this->num_products << "\n";

        // Close file
        fout.close();
    }
    // Retrieve product from text file
    static Product retrieve_from_text(std::string file_name)
    {
        // Open file
        std::ifstream fin(file_name, std::ios::in);

        // Read content
        std::string new_name;
        int new_id;
        double new_price;
        int new_nr_products;
        fin >> new_id >> new_name >> new_price >> new_nr_products;
        Product new_product(new_name, new_price, new_id, new_nr_products);

        // Close file
        fin.close();

        // Return output
        return new_product;
    }

    // Display operator
    friend std::ostream& operator<<(std::ostream& out,
        const Product& my_product);
};

// DIsplay product
std::ostream& operator<<(std::ostream& out,
    const Product& my_product)
{
    out << "ID: " << my_product.product_id << " | NAME: "
        << my_product.name << " | PRICE: "
        << my_product.price << " | NR PRODUCTS: "
        << my_product.num_products;
    return out;
}

int Product::products_nr = 0;

// Shopping bag class
template <typename T>
class ShoppingBag {
public:
    std::list<T> products_list;

public:
    // Constructors and destructor
    ShoppingBag(std::list<T> products_x)
        : products_list(products_x)
    {
    }
    ShoppingBag() = default;
    ~ShoppingBag() = default;

    // Easy access to the list
    T& operator[](int index)
    {
        auto start = products_list.begin();
        for (int i = 0; i < index; i++)
            start++;

        return *start;
    }

    // Copy constructor
    ShoppingBag(ShoppingBag& old_shopping_bag)
    {
        for (auto& el : old_shopping_bag.products_list) {
            products_list.push_back(el);
        }
        old_shopping_bag.products_list.clear();
    }

    // Display operator
    template <typename TE>
    friend std::ostream& operator<<(std::ostream& out,
        const ShoppingBag<TE>& my_shopping_bag);

    // Add and remove elements
    void Add(T produs)
    {
        products_list.push_back(produs);
    }

    void operator+=(T& produs)
    {
        products_list.push_back(produs);
    }

    void operator-=(T& produs)
    {
        products_list.remove_if([produs](T& element) -> bool {
            return element == produs;
        });
    }

    void operator=(ShoppingBag& old_shopping_bag)
    {
        for (auto& el : old_shopping_bag.products_list) {
            products_list.push_back(el);
        }
        old_shopping_bag.products_list.clear();
    }

    double shopping_list_price()
    {
        double price{ 0 };
        for (auto& el : products_list) {
            price += el.getPrice() * el.getNumProducts();
        }
        return price;
    }
};

// Display shopping bag items
template <typename TE>
std::ostream& operator<<(std::ostream& out,
    const ShoppingBag<TE>& my_shopping_bag)
{
    for (auto& el : my_shopping_bag.products_list) {
        out << el << "\n";
    }

    return out;
}

int main(void)
{
    // Create shopping bag and add some elements
    std::cout << "Creating shopping bag and adding items...\n";
    ShoppingBag<Product> my_shopping_bag;
    my_shopping_bag.Add(Product("Bread", 2, 5, 1));
    my_shopping_bag.Add(Product("Veggies", 10, 9, 2));
    my_shopping_bag.Add(Product("Chocolate", 3, 7, 1));
    my_shopping_bag.Add(Product("Wine", 20, 1, 3));

    // Display current shopping bag
    std::cout << my_shopping_bag;

    // Quick access to one item
    std::cout << "\nRenaming Chocolate to Dark Chocolate\n";
    my_shopping_bag[2].setName("Dark chocolate");

    // Test += and -= operators
    std::cout << "Testing += and -= operators on the class";
    Product item("Veggies", 10, 9, 2);
    my_shopping_bag -= item;
    std::cout << "\n\n" << my_shopping_bag;

    // Add it back
    my_shopping_bag += item;
    std::cout << "\n" << my_shopping_bag;

    // Copy class
    std::cout << "\nCopying class to another class...\n";
    ShoppingBag<Product> new_shopping_bag = my_shopping_bag;
    std::cout << new_shopping_bag;

    // Display the shopping list`s price
    std::cout << "\nTotal price is: " << new_shopping_bag.shopping_list_price() << "$\n";

    // Write product to file
    std::cout << "Save item to text file and retrieve it...\n";
    new_shopping_bag[2].save_to_text("out_file.txt");
    std::cout << Product::retrieve_from_text("out_file.txt") << "\n";

    return 0;
}
