public class LinkedStack {
    // Inner class representing a node in the list
    class Node {
        int info;
        Node link;

        Node(int info) {
            this.info = info;
            this.link = null;
        }
    }

    private Node top = null;   // Corresponds to TOP
    private Node avail = null; // Corresponds to AVAIL (the free node pool)

    /**
     * Procedure 6.3: PUSH_LINKSTACK
     * Adds an ITEM to the top of the stack.
     */
    public void push(int item) {
        // 1. [Available space?] 
        // In modern Java, we'd just use 'new Node()'. 
        // To mimic the AVAIL logic:
        Node newNode;
        if (avail == null) {
            // In a real system, we'd just create a new one, 
            // but if simulating a fixed pool:
            newNode = new Node(item); 
        } else {
            // 2. [Remove first node from AVAIL list]
            newNode = avail;
            avail = avail.link;
        }

        // 3. Set INFO[NEW] := ITEM
        newNode.info = item;

        // 4. Set LINK[NEW] := TOP
        newNode.link = top;

        // 5. Set TOP := NEW
        top = newNode;
        
        System.out.println("Pushed: " + item);
    }

    /**
     * Procedure 6.4: POP_LINKSTACK
     * Removes the top element and returns it.
     */
    public Integer pop() {
        // 1. [Stack has an item to be removed?]
        if (top == null) {
            System.out.println("UNDERFLOW");
            return null;
        }

        // 2. Set ITEM := INFO[TOP]
        int item = top.info;

        // 3. Set TEMP := TOP and TOP := LINK[TOP]
        Node temp = top;
        top = top.link;

        // 4. [Return deleted node to the AVAIL list]
        temp.link = avail;
        avail = temp;

        return item;
    }

    public void display() {
        Node current = top;
        System.out.print("Stack (Top to Bottom): ");
        while (current != null) {
            System.out.print(current.info + " -> ");
            current = current.link;
        }
        System.out.println("NULL");
    }
}