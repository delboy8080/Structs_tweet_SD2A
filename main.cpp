#include <iostream>


using namespace std;
// Tweets have the following attributes:
// author, message, ID, timestamp, geolocation (latitude and longitude).
struct tweet_struct{
    string author;
    string message;
    long int id;
    long int timestamp;
    double lat;
    double lng;
};
void display_tweet_by_reference(const tweet_struct &tweet);
void display_tweet_by_value(const tweet_struct tweet);
void display_tweet_by_pointer(const tweet_struct *tweet_ptr);
void display_tweet_by_pointer(const tweet_struct *arr, int size);
void display_tweet_by_array(const tweet_struct arr[], int size);
int main() {
    tweet_struct tweet1;
    tweet1.author = "delbot";
    tweet1.message = "My First Tweet!!!!";
    tweet1.id = 1235467890;
    tweet1.timestamp = 159864128;
    tweet1.lng = 69.1236;
    tweet1.lat = 69.365855;

    display_tweet_by_pointer(&tweet1);

    tweet_struct *tweet_ptr = new tweet_struct;
    tweet_ptr->message = "Just setting up my twttr";
    tweet_ptr->author = "Jack";
    tweet_ptr->id = 1;
    tweet_ptr->timestamp = 1000000;
    tweet_ptr->lng = 258.255555;
    tweet_ptr->lat = 28.255669;

    display_tweet_by_pointer(tweet_ptr);
    display_tweet_by_value(*tweet_ptr);
    display_tweet_by_reference(*tweet_ptr);

    tweet_struct tweets[3];
    tweets[0].id = 2;
    tweets[0].message = "Tweet #2";
    tweets[0].author = "Jack";
    tweets[0].timestamp = 1000036;
    tweets[0].lat = 2.858;
    tweets[0].lng = 2.365;
    tweets[1].id = 3;
    tweets[1].message = "Tweet #3";
    tweets[1].author = "Jill";
    tweets[1].timestamp = 1000033;
    tweets[1].lat = 3.858;
    tweets[1].lng = 3.365;
    tweets[2].id = 4;
    tweets[2].message = "Tweet #4";
    tweets[2].author = "Joan";
    tweets[2].timestamp = 10444443;
    tweets[2].lat = 4.858;
    tweets[2].lng = 4.365;

    for(int i = 0; i < 3;i++)
    {
        display_tweet_by_reference(tweets[i]);
    }

    display_tweet_by_array(tweets, 3);
    display_tweet_by_pointer(tweets, 3);
    return 0;
}
void display_tweet_by_array(const tweet_struct arr[], int size)
{

    for(int i = 0; i < size;i++)
    {
        display_tweet_by_reference(arr[i]);
    }
}

void display_tweet_by_pointer(const tweet_struct *arr, int size)
{

    for(int i = 0; i < size;i++)
    {
        display_tweet_by_pointer(arr);
        arr++;
    }
}
void display_tweet_by_value(const tweet_struct tweet)
{
    cout << string(30, '=') <<endl;
    cout << "ID: " <<tweet.id <<endl;
    cout << "Message: " << tweet.message<<endl;
    cout << tweet.author <<" (" << tweet.timestamp<<")"<<endl;
    cout << "Location: (" << tweet.lat <<", " << tweet.lng<<")" <<endl;

    cout << string(30, '=') <<endl;
}

void display_tweet_by_reference(const tweet_struct &tweet)
{
    cout << string(30, '=') <<endl;
    cout << "ID: " <<tweet.id <<endl;
    cout << "Message: " << tweet.message<<endl;
    cout << tweet.author <<" (" << tweet.timestamp<<")"<<endl;
    cout << "Location: (" << tweet.lat <<", " << tweet.lng<<")" <<endl;

    cout << string(30, '=') <<endl;
}
void display_tweet_by_pointer(const tweet_struct *tweet_ptr)
{
    cout << string(30, '=') <<endl;
    cout << "ID: " <<tweet_ptr->id <<endl;
    cout << "Message: " << tweet_ptr->message<<endl;
    cout << tweet_ptr->author <<" (" << tweet_ptr->timestamp<<")"<<endl;
    cout << "Location: (" << tweet_ptr->lat <<", " << tweet_ptr->lng<<")" <<endl;

    cout << string(30, '=') <<endl;

}