#Import Packages 
import numpy as np

# Single Node in linked list
class Node(object):
    def __init__(self,value):
        self.value = value
        self.next = None
#Linked List 
class LinkedList(object):
    #constructor make track of head
    def __init__(self,head=None):
        self.head = head

    #Append a new node to the list
    def append(self,new_node):
        current = self.head
        if current:
            while current.next:
                current = current.next
            current.next = new_node
        else:
            self.head = new_node

    '''Get an element from a particular position.
        Assume the first position is "1".
        Return "None" if position is not in the list.'''
    def get_position(self,position):
        current = self.head
        pos = 1
        if position < 1 :
            return None
        if current :
            while current and pos < position :
                current = current.next
                pos = pos+1
            if pos == position :
                return current
        return None

    """Insert a new node at a given position.
    Assume the first position is 1.
    Inserting at position 3 means between the 2nd and 3rd element."""
    def insert(self,new_node,position):
        current = self.head
        pos = 1
        if position<1 :
            return None
        if current :
            while current and pos<(position-1):
                current = current.next
                pos = pos+1
            if pos == position :
                new_node.next = current.next
                current.next = new_node
            elif position==1 :
                new_node.next = self.head
                self.head = new_node
        else :
            return None

    """ For stack implementation we need to use insert first"""
    def insert_first(self,new_node):
        new_node.next = self.head
        self.head = new_node

    """ Delete first element"""
    def delete_first(self):
        to_delete = self.head
        if self.head :
            self.head = to_delete.next
            to_delete.next = None
        return to_delete

    """ Delete and element of value"""
    def delete(self, value):
        """Delete the first node with a given value."""
        current = self.head
        previous = None
        while current.value != value and current.next:
            previous = current
            current = current.next
        if current.value == value :
            if previous :
                previous.next = current.next
            else :
                self.head = current.next

    #Display list
    def display(self):
        print 'Calling Display Function'
        current = self.head
        while current.next:
            print current.value,'->',
            current = current.next
        print current.value

    #Reverse Linked List
    def reverseLL(self):
        if (self.head == None):
            return

        curr = self.head
        prev = None
        nextNode = self.head.next

        while curr:
            curr.next = prev
            prev = curr
            curr = nextNode

            if nextNode :
                nextNode = nextNode.next

        self.head = prev





#Stack implementation
class Stack(object):
    # Constructor
    def __init__(self,top=None):
        self.ll = LinkedList(top)

    #push property -> push the node to stack and make it top
    def push(self,new_node):
        self.ll.insert_first(new_node)

    #pop property
    def pop(self):
        return self.ll.delete_first()

#Queue Implementation
class Queue(object):
    #Constructor
    def __init__(self,peek=None):
        self.ll = LinkedList(peek)

    #insert data into queue
    def enqueue(self,new_node):
        current  = self.ll
        while current.next :
            current = current.next
        current.next = new_node

    #Delete data from queue
    def dequeue(self):
        return self.ll.delete_first()

    #peek value
    def peek(self):
        return self.head

#Main Function
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node5 = Node(5)

LL1 = LinkedList()
LL1.append(node1)
LL1.append(node2)
LL1.append(node3)
print LL1.get_position(1).value
LL1.display()
LL1.reverseLL()
LL1.display()
