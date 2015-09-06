#ifndef tree_sitter_stream_methods_h
#define tree_sitter_stream_methods_h

#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <vector>
#include "compiler/prepared_grammar.h"

using std::cout;

namespace std {

template<typename T>
inline std::ostream& operator<<(std::ostream &stream, const std::vector<T> &vector) {
  stream << std::string("(vector: ");
  bool started = false;
  for (auto item : vector) {
    if (started) stream << std::string(", ");
    stream << item;
    started = true;
  }
  return stream << ")";
}

template<typename T>
inline std::ostream& operator<<(std::ostream &stream, const std::set<T> &set) {
  stream << std::string("(set: ");
  bool started = false;
  for (auto item : set) {
    if (started) stream << std::string(", ");
    stream << item;
    started = true;
  }
  return stream << ")";
}

template<typename T>
inline std::ostream& operator<<(std::ostream &stream, const std::unordered_set<T> &set) {
  stream << std::string("(set: ");
  bool started = false;
  for (auto item : set) {
    if (started) stream << std::string(", ");
    stream << item;
    started = true;
  }
  return stream << ")";
}

template<typename TKey, typename TValue>
inline std::ostream& operator<<(std::ostream &stream, const std::map<TKey, TValue> &map) {
  stream << std::string("(map: ");
  bool started = false;
  for (auto pair : map) {
    if (started) stream << std::string(", ");
    stream << pair.first;
    stream << std::string(" => ");
    stream << pair.second;
    started = true;
  }
  return stream << ")";
}

template<typename TKey, typename TValue>
inline std::ostream& operator<<(std::ostream &stream, const std::unordered_map<TKey, TValue> &map) {
  stream << std::string("(map: ");
  bool started = false;
  for (auto pair : map) {
    if (started) stream << std::string(", ");
    stream << pair.first;
    stream << std::string(" => ");
    stream << pair.second;
    started = true;
  }
  return stream << ")";
}

template<typename T1, typename T2>
inline std::ostream& operator<<(std::ostream &stream, const std::pair<T1, T2> &pair) {
  return stream << "{" << pair.first << ", " << pair.second << "}";
}

}  // namespace std

namespace tree_sitter {

using std::ostream;
using std::string;
using std::to_string;

inline ostream &operator<<(ostream &stream, const RuleEntry &entry) {
  return stream << string("{") << entry.name << string(", ") << entry.rule << string(", ") << to_string(entry.type) << string("}");
}

}

#endif
