package com.example.bookreviewapp.db;

import androidx.lifecycle.LiveData;
import androidx.room.*;
import java.util.List;

@Dao
public interface BookDao {
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    void insert(BookEntity book);

    @Delete
    void delete(BookEntity book);

    @Query("SELECT * FROM books")
    LiveData<List<BookEntity>> getAllBooks();
}
