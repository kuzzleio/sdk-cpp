#include "kuzzle.hpp"
#include "websocket.hpp"
#include <iostream>
#include <unistd.h>
#include <functional>
#include <string>
#include <exception>

using namespace kuzzleio;

int main() {
  WebSocket *ws = new WebSocket("localhost");

  Kuzzle *k = new Kuzzle(ws);

  EventListener listener = [](const std::string res) {
    std::cout << "listener added" << std::endl;
  };

  kuzzleio::KuzzleRequest request;
  request.controller = "document";
  request.action = "create";
  request.index = "my-index";
  request.collection = "my-collection";
  //request.id = "my-custom-document-id";
  request.body = R"(
    {"trip_distance": 4.23, "passenger_count": 2}
    )";

  kuzzleio::query_options options;
  options.refresh = const_cast<char*>("wait_for");

  try {
    k->connect();
    KuzzleResponse response = k->query(request, options);
    std::cout << response.request_id << std::endl;
    std::cout << response.result << std::endl;
    std::cout << response.volatiles << std::endl;
    std::cout << response.index << std::endl;
    std::cout << response.collection << std::endl;
    std::cout << response.controller << std::endl;
    std::cout << response.action << std::endl;
    std::cout << response.room_id << std::endl;
    std::cout << response.channel << std::endl;
    std::cout << response.status << std::endl;
    std::cout << response.error << std::endl;
    std::cout << response.stack << std::endl;
  
    ws->emitEvent(kuzzleio::Event::KUZZLE_EVENT_CONNECTED, "");
    
    NotificationListener *nl = new std::function<void(const kuzzleio::NotificationResult&)>([=](const kuzzleio::NotificationResult& res) {
        std::cout << "ok" << std::endl;
    });
    k->realtime->subscribe("index", "collection", "{}", nl);
    
    WebSocket *ws2 = new WebSocket("localhost");
    Kuzzle *k2 = new Kuzzle(ws2);


    k->realtime->publish("index", "collection", "{}");
  } catch (std::exception e) {
    std::cout << e.what() << std::endl;
  }
  sleep(2);

  return 0;
}
