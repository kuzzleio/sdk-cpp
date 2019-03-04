#ifndef _KUZZLE_REQUEST_HPP
#define _KUZZLE_REQUEST_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleRequest {
    public:
      std::string request_id;
      std::string controller;
      std::string action;
      std::string index;
      std::string collection;
      std::string body;
      std::string id;
      long from;
      long size;
      std::string scroll;
      std::string scroll_id;
      std::string strategy;
      unsigned long long expires_in;
      std::string volatiles;
      std::string scope;
      std::string state;
      std::string users;
      long start;
      long stop;
      long end;
      unsigned char bit;
      std::string member;
      std::string member1;
      std::string member2;
      std::vector<std::string> members;
      double lon;
      double lat;
      double distance;
      std::string unit;
      std::vector<std::string> options;
      std::vector<std::string> keys;
      long cursor;
      long offset;
      std::string field;
      std::vector<std::string> fields;
      std::string subcommand;
      std::string pattern;
      long idx;
      std::string min;
      std::string max;
      std::string limit;
      unsigned long count;
      std::string match;
      bool reset;
      bool include_trash;

      KuzzleRequest(const kuzzle_request* u) :
        request_id(u->request_id),
        controller(u->controller),
        action(u->action),
        index(u->index),
        collection(u->collection),
        body(u->body),
        id(u->id),
        from(u->from),
        size(u->size),
        scroll(u->scroll),
        scroll_id(u->scroll_id),
        strategy(u->strategy),
        expires_in(u->expires_in),
        volatiles(u->volatiles),
        scope(u->scope),
        state(u->state),
        users(u->users),
        start(u->start),
        stop(u->stop),
        end(u->end),
        bit(u->bit),
        member(u->member),
        member1(u->member1),
        member2(u->member2),
        members(std::vector<std::string>(u->members, u->members + u->members_length)),
        lon(u->lon),
        lat(u->lat),
        distance(u->distance),
        unit(u->unit),
        options(std::vector<std::string>(u->options, u->options + u->options_length)),
        keys(std::vector<std::string>(u->keys, u->keys + u->keys_length)),
        cursor(u->cursor),
        offset(u->offset),
        field(u->field),
        fields(std::vector<std::string>(u->fields, u->fields + u->fields_length)),
        subcommand(u->subcommand),
        pattern(u->pattern),
        idx(u->idx),
        min(u->min),
        max(u->max),
        limit(u->limit),
        count(u->count),
        match(u->match),
        reset(u->reset),
        include_trash(u->include_trash)
        {};
      KuzzleRequest(KuzzleRequest* u) :
        request_id(u->request_id),
        controller(u->controller),
        action(u->action),
        index(u->index),
        collection(u->collection),
        body(u->body),
        id(u->id),
        from(u->from),
        size(u->size),
        scroll(u->scroll),
        scroll_id(u->scroll_id),
        strategy(u->strategy),
        expires_in(u->expires_in),
        volatiles(u->volatiles),
        scope(u->scope),
        state(u->state),
        users(u->users),
        start(u->start),
        stop(u->stop),
        end(u->end),
        bit(u->bit),
        member(u->member),
        member1(u->member1),
        member2(u->member2),
        members(u->members),
        lon(u->lon),
        lat(u->lat),
        distance(u->distance),
        unit(u->unit),
        options(u->options),
        keys(u->keys),
        cursor(u->cursor),
        offset(u->offset),
        field(u->field),
        fields(u->fields),
        subcommand(u->subcommand),
        pattern(u->pattern),
        idx(u->idx),
        min(u->min),
        max(u->max),
        limit(u->limit),
        count(u->count),
        match(u->match),
        reset(u->reset),
        include_trash(u->include_trash)
        {};
  };
}

#endif