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
  request.setController("document");
  request.setAction("create");
  request.setIndex("my-index");
  request.setCollection("my-collection");
  //request.id = "my-custom-document-id";
  request.setBody(R"(
    {"trip_distance": 4.23, "passenger_count": 2}
    )");

  kuzzleio::QueryOptions options;
  options.setRefresh("wait_for");

  try {
    k->connect();
    KuzzleResponse response = k->query(request, options);
    std::cout << response.getRequestId() << std::endl;
    std::cout << response.getResult() << std::endl;
    std::cout << response.getVolatiles() << std::endl;
    std::cout << response.getIndex() << std::endl;
    std::cout << response.getCollection() << std::endl;
    std::cout << response.getController() << std::endl;
    std::cout << response.getAction() << std::endl;
    std::cout << response.getRoomId() << std::endl;
    std::cout << response.getChannel() << std::endl;
    std::cout << response.getStatus() << std::endl;
    std::cout << response.getError() << std::endl;
    std::cout << response.getStack() << std::endl;
  
    ws->emitEvent(kuzzleio::Event::KUZZLE_EVENT_CONNECTED, "");
    
    NotificationListener *nl = new std::function<void(const kuzzleio::NotificationResult&)>([=](const kuzzleio::NotificationResult& res) {
        std::cout << "ok" << std::endl;
    });
    k->realtime->subscribe("index", "collection", "{}", nl);
    
    WebSocket *ws2 = new WebSocket("localhost");
    Kuzzle *k2 = new Kuzzle(ws2);


    k->realtime->publish("index", "collection", "{}");
  } catch (std::exception &e) {
    std::cout << "fail:" << e.what() << std::endl;
  }
  sleep(2);

  return 0;
}
