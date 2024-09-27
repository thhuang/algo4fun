class MyCalendar {
    private TreeMap<Integer, Integer> events;

    public MyCalendar() {
        events = new TreeMap();
    }

    public boolean book(int start, int end) {
        Integer l = events.floorKey(start);
        Integer r = events.ceilingKey(start);
        if (l != null && start < events.get(l)) return false;
        if (r != null && r < end) return false;
        events.put(start, end);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */