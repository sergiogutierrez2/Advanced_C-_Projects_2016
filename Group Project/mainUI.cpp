#include "BST.cpp"
#include "Search.cpp"
#include <iostream>

using namespace std;

int main() {
    BST<Song> bst;
    Search se;
    se.buildAssignmentTable();
    se.buildInvertedIndex();
    string files[15] = { "almightygosh.txt", "areweready.txt", "byebye.txt", "electrify.txt", "explotar.txt", "highandlow.txt", "painting.txt",
                        "paperroute.txt", "porcelain.txt", "raging.txt", "sameoldblues.txt", "sendthemoff.txt", "shelter.txt", "surprise.txt", "tearingmeup.txt"};
    for (int i = 0; i < 15; i++){
        Song s;
        ifstream fin(files[i]);
        if(fin.fail()){
            cout << "Input failed to open" << endl;
            exit(-1);
        }

        string line;
        getline(fin, line); //first line
        s.set_artist(line);
        getline(fin, line); //second line
        s.set_title(line);
        getline(fin, line); //third line
        s.set_genre(line);
        getline(fin, line);
        getline(fin, line);

        string lyric;

        while(getline(fin, line)){ //get rest of the line
            lyric += "\n" + line;
            s.set_lyrics(lyric);
        }
        bst.insert(s);//insert s to the BST
    }

    int input;

do
    {

    cout << endl << "1. Display Catalog." << endl;
    cout << "2. Remove Song." << endl;
    cout << "3. Add Song." << endl;
    cout << "4. Search for Song." << endl;
    cout << "5. Download Song." << endl;
    cout << "6. Statistics." << endl;
    cout << "7. End program." << endl;
    cout << "Type number according to your selection." << endl;
    cin >> input;
    cin.ignore(1000, '\n');

    if (input == 1)
    {
        int in;
        cout << "Song Catalog." << endl;
        cout << "1. Unsorted Song List" << endl;
        cout << "2. Song List sorted by Title" << endl;
        cout << "3. Return" << endl;
        cin >> in;
        cin.ignore(1000, '\n');
        if (in == 1) {
            bst.preOrderPrint();    //call post or pre order print on the BST
            cout << endl;
        }

        if (in == 2) {
            bst.inOrderPrint();      //call inOrderPrint on the BST
        }

        if (in == 3) {

        }
    }

    else if (input == 2) {
        string song;
        cout << "Please type in the song name that you wish to remove:" << endl;
        getline(cin, song);
        bst.remove(song);
        se.remove(song);
        //cout << "Song has been successfully removed!" << endl;
    }

    else if (input == 3)
    {
        string title;
        string artist;
        string genre;
        string lyrics;
        cout << "Title: ";
        cin.ignore(1000, '\n');
        getline(cin, title);
        cout << "Artist: ";
        getline(cin, artist);
        cout << "Genre: ";
        getline(cin, genre);
        cout << "Lyrics: ";
        getline(cin, lyrics);
        Song s(title, artist, genre, lyrics);
        bst.insert(s);
        se.insert(s);
        cout << "Song has been added to the list." << endl;
    }

    else if (input == 4)
    {
        int in;
        cout << "Search Submenu" << endl;
        cout << "1. Search by Artist" << endl;
        cout << "2. Search by Song Title" << endl;
        cout << "3. Search by Genre" << endl;
        cout << "4. Search by Lyrics" << endl;
        cin >> in;
        cin.ignore(1000, '\n');
        if (in == 1)
        {
        string artist1;
        cout << "Search a song by it's artist." << endl;
        cout << "Type in the artist name you wish to search for: " << endl;
        getline(cin, artist1);
        cout << endl;
        bst.find_by_artist(artist1);
        }

        if (in == 2)
        {
        string title1;
        cout << "Search a song by the song name." << endl;
        cout << "Type in the song name you wish to search for: " << endl;
        getline(cin, title1);
        cout << endl;
        bst.find_by_title(title1);
        }

        if (in == 3)
        {
            string genre1;
            cout << "Search a song by genre." << endl;
            cout << "Type in the genre you wish to search for: " << endl;
            getline(cin, genre1);
            cout << endl;
            bst.find_by_genre(genre1);
        }

        if (in == 4)
        {
            string keyword;
            cout << "Search a song by the lyrics." << endl;
            cout << "Type in a word you wish to search for: " << endl;
            cin >> keyword;
            cin.ignore(1000, '\n');
            cout << endl;
            se.searchKeyword(keyword);
        }

    }

    else if (input == 5)
    {
        ofstream fout("download.txt");
        string title2;
        cout << "Type in the song title to be downloaded: " << endl;
        getline(cin, title2);
        bst.download_by_title(title2, fout);
    }

    else if(input == 6)
    {
        int input2;
        cout << "1. Number of Genres in the Soundtrack." << endl;
        cout << "2. Number of Songs in each genre." << endl;
        cout << "3. Number of Songs in list." << endl;
        if (input2 == 1) {

        }
        if (input2 == 2) {

        }

        if (input2 == 3) {
            cout << bst.getSize() << endl;
        }

    }

    else if (input ==7)
    {
        cout << "Program is now ending." << endl;
        input = -1;
    }

    else
    {
    cout << "Invalid option." << endl;
    }


} while (input != -1);


    return 0;
}



