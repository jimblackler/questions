package net.jimblacker.questions;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Random;

public class MostEvents {
  static class Event {
    long start;
    long duration;
  }

  private static long maxEventsFrom(
      long minimumTime, List<Event> events) {
    long maxEvents = 0;
    for (Event event : events) {
      if (event.start >= minimumTime)
        maxEvents = Math.max(maxEvents, 1 +
            maxEventsFrom(event.start + event.duration, events));
    }
    return maxEvents;
  }

  private static long maxEvents(List<Event> events) {
    return maxEventsFrom(0, events);
  }

  static class MaxEventsFrom {
    long from;
    long maxEvents;
  }

  private static long maxEvents2(List<Event> events) {
    Comparator<MaxEventsFrom> comparator =
        new Comparator<MaxEventsFrom>() {
      public int compare(MaxEventsFrom o1, MaxEventsFrom o2) {
        return Long.valueOf(o1.from).compareTo(o2.from);
      }
    };
    PriorityQueue<MaxEventsFrom> maxEventsFrom =
        new PriorityQueue<MaxEventsFrom>(1, comparator);
    long maxEvents = 0;
    for (Event event : events) {
      while (!maxEventsFrom.isEmpty() &&
          maxEventsFrom.peek().from <= event.start) {
        maxEvents =
            Math.max(maxEvents, maxEventsFrom.remove().maxEvents);
      }
      MaxEventsFrom record = new MaxEventsFrom();
      record.from = event.start + event.duration;
      record.maxEvents = maxEvents + 1;
      maxEventsFrom.add(record);
    }
    while (!maxEventsFrom.isEmpty()) {
      maxEvents =
          Math.max(maxEvents, maxEventsFrom.remove().maxEvents);
    }
    return maxEvents;
  }

  public static void main(String[] args) {
    Random random = new Random(3);

    List<Event> events = new ArrayList<Event>();
    for (int count = 0; count != 42; count++) {
      Event event = new Event();
      event.start = random.nextInt(100);
      event.duration = random.nextInt(10) + 1;
      events.add(event);
    }
    Collections.sort(events, new Comparator<Event>() {
      @Override
      public int compare(Event o1, Event o2) {
        return Long.valueOf(o1.start).compareTo(o2.start);
      }
    });
    System.out.println(maxEvents(events));
    System.out.println(maxEvents2(events));

  }


}
