/*
 * main.cpp
 *
 *  Created on: Jul 18, 2014
 *      Author: rudolpharaujo
 */




// Implement a hashtable in C or C++
// get(void *key)
// put(void *key, void *value)
// long hash(void *key) given


// data d = new data();
// d.put(key, value);
// value = d.get(key);

Hash table implementation
	http://www.algolist.net/Data_structures/Hash_table/Open_addressin	g#open_addressing_vs_chaining
	http://www.algolist.net/Data_structures/Hash_table/Chain	ing

class data
{
    private:
       void  *arr [10];
    public:
        data ();
        put (void *key, void *value);
        T get(void *key);
};

data::data ()
{
    // Initialize
}

data::put (void *key, void *value)
{
    long key_id = hash (key);

    if (key_id >= 0 && key_id < 10)
    {
        if ((arr[key_id]) != NULL)
        {
            // handle collision
            Node *head = arr [key_id];

            //1. Create a node
            Node *ptr = new Node();
            ptr->data.key = key_id;
            ptr->data.value = value;
            ptr->next = NULL;

            // add it to the existing list
            ptr->next = head ->next;
            head = ptr;
        }
        else
        {
            // create a link list and add
            arr [key_id] = (int*)(value);
        }
    }
}


T data::get (void *key)
{
    // Assuming that the value for the key exists
    T ret_value = 0;
    long key_id = hash (key);
    if (key_id >= 0 && key_id < 10)
    {
        Node *ptr = arr [key_id];

        // Traverse the list
        while (ptr)
        {
            if (ptr->data.key == key_id)
            {
                ret_value = [tr->data.value;
                return ret_value;
            }
        }
    }

    return ret_value;
}
