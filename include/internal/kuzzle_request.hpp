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
      KuzzleRequest(const kuzzle_request* u) :
        _requestId(u->request_id),
        _controller(u->controller),
        _action(u->action),
        _index(u->index),
        _collection(u->collection),
        _body(u->body),
        _id(u->id),
        _from(u->from),
        _size(u->size),
        _scroll(u->scroll),
        _scrollId(u->scroll_id),
        _strategy(u->strategy),
        _expiresIn(u->expires_in),
        _volatiles(u->volatiles),
        _scope(u->scope),
        _state(u->state),
        _users(u->users),
        _start(u->start),
        _stop(u->stop),
        _end(u->end),
        _bit(u->bit),
        _member(u->member),
        _member1(u->member1),
        _member2(u->member2),
        _members(std::vector<std::string>(u->members, u->members + u->members_length)),
        _lon(u->lon),
        _lat(u->lat),
        _distance(u->distance),
        _unit(u->unit),
        _options(std::vector<std::string>(u->options, u->options + u->options_length)),
        _keys(std::vector<std::string>(u->keys, u->keys + u->keys_length)),
        _cursor(u->cursor),
        _offset(u->offset),
        _field(u->field),
        _fields(std::vector<std::string>(u->fields, u->fields + u->fields_length)),
        _subcommand(u->subcommand),
        _pattern(u->pattern),
        _idx(u->idx),
        _min(u->min),
        _max(u->max),
        _limit(u->limit),
        _count(u->count),
        _match(u->match),
        _reset(u->reset),
        _includeTrash(u->include_trash)
        {};

      KuzzleRequest(const KuzzleRequest& u) : KuzzleRequest(u.toC()) {};

      KuzzleRequest() {}

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