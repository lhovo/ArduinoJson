// ArduinoJson - arduinojson.org
// Copyright Benoit Blanchon 2014-2018
// MIT License

#pragma once

#include "Data/ListIterator.hpp"
#include "JsonVariant.hpp"

namespace ArduinoJson {

class JsonVariantPtr {
 public:
  JsonVariantPtr(Internals::JsonVariantData *data) : _variant(data) {}

  const JsonVariant *operator->() const {
    return &_variant;
  }

  const JsonVariant &operator*() const {
    return _variant;
  }

 private:
  JsonVariant _variant;
};

class JsonArrayIterator {
  typedef Internals::ListIterator<Internals::JsonVariantData> internal_iterator;

 public:
  JsonArrayIterator() {}
  explicit JsonArrayIterator(internal_iterator iterator)
      : _iterator(iterator) {}

  JsonVariant operator*() const {
    return JsonVariant(&*_iterator);
  }
  JsonVariantPtr operator->() {
    return JsonVariantPtr(&*_iterator);
  }

  bool operator==(const JsonArrayIterator &other) const {
    return _iterator == other._iterator;
  }

  bool operator!=(const JsonArrayIterator &other) const {
    return _iterator != other._iterator;
  }

  JsonArrayIterator &operator++() {
    ++_iterator;
    return *this;
  }

  JsonArrayIterator &operator+=(size_t distance) {
    _iterator += distance;
    return *this;
  }

  internal_iterator internal() {
    return _iterator;
  }

 private:
  internal_iterator _iterator;
};
}  // namespace ArduinoJson
