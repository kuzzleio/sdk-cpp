#ifndef _KUZZLE_REQUEST_HPP
#define _KUZZLE_REQUEST_HPP

#include <string>
#include <vector>
#include "core.hpp"

namespace kuzzleio {
  class KuzzleRequest {
    public:
      const std::string &getRequest_id() const;

      void setRequest_id(const std::string &request_id);

      const std::string &getController() const;

      void setController(const std::string &controller);

      const std::string &getAction() const;

      void setAction(const std::string &action);

      const std::string &getIndex() const;

      void setIndex(const std::string &index);

      const std::string &getCollection() const;

      void setCollection(const std::string &collection);

      const std::string &getBody() const;

      void setBody(const std::string &body);

      const std::string &getId() const;

      void setId(const std::string &id);

      long getFrom() const;

      void setFrom(long from);

      long getSize() const;

      void setSize(long size);

      const std::string &getScroll() const;

      void setScroll(const std::string &scroll);

      const std::string &getScroll_id() const;

      void setScroll_id(const std::string &scroll_id);

      const std::string &getStrategy() const;

      void setStrategy(const std::string &strategy);

      unsigned long long int getExpires_in() const;

      void setExpires_in(unsigned long long int expires_in);

      const std::string &getVolatiles() const;

      void setVolatiles(const std::string &volatiles);

      const std::string &getScope() const;

      void setScope(const std::string &scope);

      const std::string &getState() const;

      void setState(const std::string &state);

      const std::string &getUsers() const;

      void setUsers(const std::string &users);

      long getStart() const;

      void setStart(long start);

      long getStop() const;

      void setStop(long stop);

      long getEnd() const;

      void setEnd(long end);

      unsigned char getBit() const;

      void setBit(unsigned char bit);

      const std::string &getMember() const;

      void setMember(const std::string &member);

      const std::string &getMember1() const;

      void setMember1(const std::string &member1);

      const std::string &getMember2() const;

      void setMember2(const std::string &member2);

      const std::vector<std::string> &getMembers() const;

      void setMembers(const std::vector<std::string> &members);

      double getLon() const;

      void setLon(double lon);

      double getLat() const;

      void setLat(double lat);

      double getDistance() const;

      void setDistance(double distance);

      const std::string &getUnit() const;

      void setUnit(const std::string &unit);

      const std::vector<std::string> &getOptions() const;

      void setOptions(const std::vector<std::string> &options);

      const std::vector<std::string> &getKeys() const;

      void setKeys(const std::vector<std::string> &keys);

      long getCursor() const;

      void setCursor(long cursor);

      long getOffset() const;

      void setOffset(long offset);

      const std::string &getField() const;

      void setField(const std::string &field);

      const std::vector<std::string> &getFields() const;

      void setFields(const std::vector<std::string> &fields);

      const std::string &getSubcommand() const;

      void setSubcommand(const std::string &subcommand);

      const std::string &getPattern() const;

      void setPattern(const std::string &pattern);

      long getIdx() const;

      void setIdx(long idx);

      const std::string &getMin() const;

      void setMin(const std::string &min);

      const std::string &getMax() const;

      void setMax(const std::string &max);

      const std::string &getLimit() const;

      void setLimit(const std::string &limit);

      unsigned long getCount() const;

      void setCount(unsigned long count);

      const std::string &getMatch() const;

      void setMatch(const std::string &match);

      bool isReset() const;

      void setReset(bool reset);

      bool isInclude_trash() const;

      void setInclude_trash(bool include_trash);

      kuzzle_request* toC() const;
 // private:
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

      std::string getRequestId() const;

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

        KuzzleRequest() = default;
  };
}

#endif