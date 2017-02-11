#pragma once

#include "headers.h"

#include <vector>
#include <string>
#include <unordered_map>

template <class T>
class Named_value
{
  public:
    Named_value() {}

    Named_value(std::pair<T, std::string> pair)
    {
      _value = pair.first;
      _name = pair.second;
    }

    T& get_value()
    {
      return _value;
    }

    std::string get_name()
    {
      return _name;
    }

    const T& get_value() const
    {
      return _value;
    }

    const std::string& get_name() const
    {
      return _name;
    }

    void set_value(const T& value)
    {
      _value = value;
    }

  private:
    T _value;
    std::string _name;
};

class Named_values_containers_factory;

template <class T>
class Named_values_container
{
    friend Named_values_containers_factory;

  public:
    Named_values_container(const std::vector<std::pair<T, std::string>>& elements)
    {
      _container.reserve(elements.size());
      for (size_t i = 0; i < elements.size(); ++i)
      {
        _container.emplace_back(elements[i]);
        _elements_ids.insert(std::make_pair(elements[i].second, i));
      }
    };

    T& operator [] (size_t index)
    {
      return _container[index].get_value();
    }

    T& operator [] (const std::string& name)
    {
      return _container[_elements_ids[name]].get_value();
    }

    T& operator [] (const std::string& name) const
    {
      return (*this)[name];
    }

    size_t size() const
    {
      return _container.size();
    }

    auto begin() const
    {
      return _container.begin();
    }

    auto end() const
    {
      return _container.end();
    }

    auto begin()
    {
      return _container.begin();
    }

    auto end()
    {
      return _container.end();
    }

    ~Named_values_container()
    {};

  protected:
    Named_values_container(const std::vector <Named_value<T> >& elements,
                        const std::unordered_map <std::string, size_t>& elements_ids) :
      _container(elements),
      _elements_ids(elements_ids)
    {
    };

    Named_values_container(const std::vector <std::pair<T, std::string> >& elements,
                        const std::unordered_map <std::string, size_t>& elements_ids) :
      _elements_ids(elements_ids)
    {
      _container.reserve(elements.size());
      for (auto element : elements)
      {
        _container.emplace_back(element);
      }
    };

    std::vector <Named_value<T> > _container;
    std::unordered_map < std::string, size_t > _elements_ids;
};
