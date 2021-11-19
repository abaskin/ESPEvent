# ESP Event Library

This is simple event handling library for the ESP8266/ESP32 which allows functions
to be assigned to events, events enqueued, and events to be processed.

## Using the library

An ESPEvent object is first created specifying the type of the event and the
event handling function. Functions are then assigned to events, events are
enqueued, and the event queue is processed. The event queue will continue to be
processed until an event handling function returns false. Events for which no
handling function has been assigned are ignored.

## Declaring the ESPEvent object

```c++
template <typename T, typename F>
ESPEvent objectName(T idle);
```

- **T** - the event type
- **F** - the event handling function type, this function must return bool
- **idle** - the event to process when the event queue is empty

## Object Methods

```c++
Event& enqueue(T event)
```

- **event** - the event to enqueue

Enqueue an event to be processed

```c++
Event& setFunction(T event, F function)
```

- **event** - the event to handle
- **function** - the event handling function

Set the handling function for a given event.

```c++
void run()
```

Process the events in the queue. This function will run until a event handling
function returns false.
