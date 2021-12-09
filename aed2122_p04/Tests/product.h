#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <system_error>

using namespace std;

class Product : public error_code {
    string id;
    float price;
    float weight;
public:
    Product(string i, float p, float w);
    string getId() const;
    float getPrice() const;
    float getWeight() const;
};
#endif
