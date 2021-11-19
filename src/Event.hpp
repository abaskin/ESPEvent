#pragma once

#include <functional>
#include <queue>
#include <unordered_map>
    
template <typename T, typename F> 
class Event {
  public:
    Event(T idle) : m_idle(idle) {}
    ~Event(){}

    Event& enqueue(T event) {
      m_eventQueue.emplace(event);
      return *this;
    }

    Event& setFunction(T event, F function) {
      m_eventFunctions.emplace(event, function);
      return *this;
    }

    void run(){
      do {
        if (callFunction(dequeue()) == false) { return; }
      } while (true);
    }

  private:
    T dequeue() {
      if (m_eventQueue.empty()) { return m_idle; }
      auto event = m_eventQueue.front();
      m_eventQueue.pop();
      return event;
    }

    bool callFunction(T event) {
      return (m_eventFunctions.find(event) != m_eventFunctions.end())
       ? m_eventFunctions.at(event)()
       : true;
    }

    const T m_idle;
    std::unordered_map<T, F> m_eventFunctions;
    std::queue<T> m_eventQueue;
};