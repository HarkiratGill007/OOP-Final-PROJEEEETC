#include "inventory.h"
#include <string>
int Inventory::get_qty()
{
    return i_qty;
}
void Inventory::i_increment()
{
    i_qty += 1;
}
void Inventory::i_decrement()
{
    i_qty -= 1;
}
std::string Inventory::drop(std::string _name)
{
    for (size_t i = 0; i < obj_arr.size(); i++)
    {
        if (obj_arr[i]->get_name() == _name)
        {
            obj_arr[i]->decrement();
            i_decrement();
            if (obj_arr[i]->get_qty() < 1)
            {
                obj_arr.erase(obj_arr.begin() + i);
            }
            return "1 " + _name + " was dropped!";
        }
    }
    return _name + " not found in inventory.";
}

std::string Inventory::grab(std::unique_ptr<Object> obj)
{
    if (i_qty < 5)
    {
        i_increment();
        for (size_t i = 0; i < obj_arr.size(); i++)
        {
            if (obj_arr[i]->get_name() == obj->get_name())
            {
                obj_arr[i]->increment();

                return "1 " + obj->get_name() + " was grabbed";
            }
        }
        std::string msg = "1 " + obj->get_name() + " was grabbed!\n" + obj->get_description();
        obj_arr.push_back(std::move(obj)); // <- actually store it
        return msg;
    }
    return "No more than 5 objects can be handled";
}
std::string Inventory::useItem(std::string _name)
{
    for (size_t i = 0; i < obj_arr.size(); i++)
    {
        if (obj_arr[i]->get_name() == _name)
        {
            std::string result = obj_arr[i]->use();
            i_decrement();
            if (obj_arr[i]->get_qty() < 1)
            {
                obj_arr.erase(obj_arr.begin() + i);
            }
            return result;
        }
    }
    return _name + " not found in inventory.";
}
// to_json is for obj_arr in inventory , toJson is for obj
void to_json(json &j, const Inventory &inv)
{
    json arr = json::array();
    for (const auto &yo : inv.obj_arr)
    {
        if (o)
            arr.push_back(o->toJson());
    }
    j = {{"items", arr}, {"i_qty", inv.i_qty}};
}
void from_json(const nlohmann::json &j, Inventory &inv)
{
    inv.obj_arr.clear();
    inv.i_qty = j.value("i_qty", 0);
    for (const auto &item : j.at("items"))
    {
        Object *o = makeObject(item); // your factory
        std::unique_ptr<Object> o(makeObject(item));
        if (o)
            inv.obj_arr.push_back(std::move(o));
    }
}