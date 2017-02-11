#pragma once

#include "headers.h"

#include "Named_values_container.hpp"
#include "Named_values_containers_factory.hpp"

#define ION_PARTICLE_TYPE_NAME "ion"
#define ELECTRON_PARTICLE_TYPE_NAME "electron"
#define NEUTRAL_PARTICLE_TYPE_NAME "neutral"


enum class Particle_types
{
    ION,
    ELECTRON,
    NEUTRAL
};

template <typename T>
class Particle_types_container : public Named_values_container<T>
{
  public:
    Particle_types_container(const std::vector<std::pair<T, std::string>>& elements) :
      Named_values_container<T>(elements)
    { }

    Particle_types_container(const std::vector <std::pair <T, std::string> >& elements,
                           const std::unordered_map <std::string, size_t>& elements_ids) :
      Named_values_container<T>(elements, elements_ids)
    { }

    T& operator [] (const std::string& name)
    {
      return Named_values_container<T>::operator [] (name);
    }

    T& operator [] (const std::string& name) const
    {
      return Named_values_container<T>::operator [] (name);
    }

    T& operator [] (Particle_types group) const
    {
      return (*this)[particle_type_to_string(group)];
    }

  protected:
    static std::string particle_type_to_string(Particle_types particle_type)
    {
      switch (particle_type)
      {
        case Particle_types::ION:
          return ION_PARTICLE_TYPE_NAME;

        case Particle_types::ELECTRON:
          return ELECTRON_PARTICLE_TYPE_NAME;

        case Particle_types::NEUTRAL:
          return NEUTRAL_PARTICLE_TYPE_NAME;

        default:
          return ELECTRON_PARTICLE_TYPE_NAME;
      }
    }
};

class Particle_types_containers_factory : public Named_values_containers_factory
{
  public:
    Particle_types_containers_factory(const std::vector<std::string>& elements_names) :
      Named_values_containers_factory(elements_names)
    { }

    template <class T>
    Particle_types_container<T> make_container(const std::vector<T>& values) const
    {
      // TODO: add assert or something else

      return Particle_types_container<T>(
        Named_values_containers_factory::make_elements(values, this->_elements_names),
        _elements_ids);
    };

    template <class T>
    Particle_types_container<T> make_container() const
    {
      return make_container<T>(std::vector<T>(this->_elements_names.size(), T()));
    };
};