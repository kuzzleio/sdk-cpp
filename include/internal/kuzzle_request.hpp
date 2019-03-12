#ifndef _KUZZLE_REQUEST_HPP
#define _KUZZLE_REQUEST_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleRequest {
    private:
      std::string _requestId;
      std::string _controller;
      std::string _action;
      std::string _index;
      std::string _collection;
      std::string _body;
      std::string _id;
      long _from;
      long _size;
      std::string _scroll;
      std::string _scrollId;
      std::string _strategy;
      unsigned long long _expiresIn;
      std::string _volatiles;
      std::string _scope;
      std::string _state;
      std::string _users;
      long _start;
      long _stop;
      long _end;
      unsigned char _bit;
      std::string _member;
      std::string _member1;
      std::string _member2;
      std::vector<std::string> _members;
      double _lon;
      double _lat;
      double _distance;
      std::string _unit;
      std::vector<std::string> _options;
      std::vector<std::string> _keys;
      long _cursor;
      long _offset;
      std::string _field;
      std::vector<std::string> _fields;
      std::string _subcommand;
      std::string _pattern;
      long _idx;
      std::string _min;
      std::string _max;
      std::string _limit;
      unsigned long _count;
      std::string _match;
      bool _reset;
      bool _includeTrash;

  public:
      KuzzleRequest() :
        _from(0),
        _size(0),
        _expiresIn(0),
        _start(0),
        _stop(0),
        _end(0),
        _bit(0),
        _lon(0),
        _lat(0),
        _distance(0),
        _cursor(0),
        _offset(0),
        _idx(0),
        _count(0),
        _reset(false),
        _includeTrash(false)
        {};
      KuzzleRequest(const kuzzle_request* src) :
        _requestId(src->request_id),
        _controller(src->controller),
        _action(src->action),
        _index(src->index),
        _collection(src->collection),
        _body(src->body),
        _id(src->id),
        _from(src->from),
        _size(src->size),
        _scroll(src->scroll),
        _scrollId(src->scroll_id),
        _strategy(src->strategy),
        _expiresIn(src->expires_in),
        _volatiles(src->volatiles),
        _scope(src->scope),
        _state(src->state),
        _users(src->users),
        _start(src->start),
        _stop(src->stop),
        _end(src->end),
        _bit(src->bit),
        _member(src->member),
        _member1(src->member1),
        _member2(src->member2),
        _members(std::vector<std::string>(src->members, src->members + src->members_length)),
        _lon(src->lon),
        _lat(src->lat),
        _distance(src->distance),
        _unit(src->unit),
        _options(std::vector<std::string>(src->options, src->options + src->options_length)),
        _keys(std::vector<std::string>(src->keys, src->keys + src->keys_length)),
        _cursor(src->cursor),
        _offset(src->offset),
        _field(src->field),
        _fields(std::vector<std::string>(src->fields, src->fields + src->fields_length)),
        _subcommand(src->subcommand),
        _pattern(src->pattern),
        _idx(src->idx),
        _min(src->min),
        _max(src->max),
        _limit(src->limit),
        _count(src->count),
        _match(src->match),
        _reset(src->reset),
        _includeTrash(src->include_trash)
        {};

      KuzzleRequest(const KuzzleRequest& src) : KuzzleRequest(src.toC()) {};

      const std::string &requestId() const;

      void requestId(const std::string &requestId);

      const std::string &controller() const;

      void controller(const std::string &controller);

      const std::string &action() const;

      void action(const std::string &action);

      const std::string &index() const;

      void index(const std::string &index);

      const std::string &collection() const;

      void collection(const std::string &collection);

      const std::string &body() const;

      void body(const std::string &body);

      const std::string &id() const;

      void id(const std::string &id);

      long from() const;

      void from(long from);

      long size() const;

      void size(long size);

      const std::string &scroll() const;

      void scroll(const std::string &scroll);

      const std::string &scrollId() const;

      void scrollId(const std::string &scrollId);

      const std::string &strategy() const;

      void strategy(const std::string &strategy);

      unsigned long long int expiresIn() const;

      void expiresIn(unsigned long long int expiresIn);

      const std::string &volatiles() const;

      void volatiles(const std::string &volatiles);

      const std::string &scope() const;

      void scope(const std::string &scope);

      const std::string &state() const;

      void state(const std::string &state);

      const std::string &users() const;

      void users(const std::string &users);

      long start() const;

      void start(long start);

      long stop() const;

      void stop(long stop);

      long end() const;

      void end(long end);

      unsigned char bit() const;

      void bit(unsigned char bit);

      const std::string &member() const;

      void member(const std::string &member);

      const std::string &member1() const;

      void member1(const std::string &member1);

      const std::string &member2() const;

      void member2(const std::string &member2);

      const std::vector<std::string> &members() const;

      void members(const std::vector<std::string> &members);

      double lon() const;

      void lon(double lon);

      double lat() const;

      void lat(double lat);

      double distance() const;

      void distance(double distance);

      const std::string &unit() const;

      void unit(const std::string &unit);

      const std::vector<std::string> &options() const;

      void options(const std::vector<std::string> &options);

      const std::vector<std::string> &keys() const;

      void keys(const std::vector<std::string> &keys);

      long cursor() const;

      void cursor(long cursor);

      long offset() const;

      void offset(long offset);

      const std::string &field() const;

      void field(const std::string &field);

      const std::vector<std::string> &fields() const;

      void fields(const std::vector<std::string> &fields);

      const std::string &subcommand() const;

      void subcommand(const std::string &subcommand);

      const std::string &pattern() const;

      void pattern(const std::string &pattern);

      long idx() const;

      void idx(long idx);

      const std::string &min() const;

      void min(const std::string &min);

      const std::string &max() const;

      void max(const std::string &max);

      const std::string &limit() const;

      void limit(const std::string &limit);

      unsigned long count() const;

      void count(unsigned long count);

      const std::string &match() const;

      void match(const std::string &match);

      bool reset() const;

      void reset(bool reset);

      bool includeTrash() const;

      void includeTrash(bool includeTrash);

      kuzzle_request* toC() const;
  };
}

#endif