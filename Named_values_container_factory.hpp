#pragma once

#include "Named_values_container.hpp"

class Named_values_containers_factory
{
  public:
    Named_values_containers_factory(const std::vector<std::string>& elements_names) :
      _elements_names(elements_names)
    {
      for (size_t i = 0; i < _elements_names.size(); ++i)
      {
        _elements_ids.insert(std::make_pair(_elements_names[i], i));
      }
    };

    ~Named_values_containers_factory()
    {
    };

    template <class T>
    Named_values_container<T> make_container(const std::vector<T>& values) const
    {
      // TODO: add assert or something else

      return Named_values_container<T>(make_elements<T>(values), _elements_ids);
    };

    template <class T>
    Named_values_container<T> make_container() const
    {
      return make_container(std::vector<T>(_elements_names.size(), T()));
    };

  protected:
    template <class T>
    static std::vector <std::pair <T, std::string> > make_elements(const std::vector<T>& values
      , const std::vector<std::string>& names)
    {
      std::vector <std::pair <T, std::string> > result(names.size());
      for (size_t i = 0; i < names.size() && i < values.size(); ++i)
      {
        result.push_back(std::make_pair(values[i], names[i]));
      }
      return result;
    }

    std::vector<std::string> _elements_names;
    std::unordered_map<std::string, size_t> _elements_ids;
};