package com.example.bookreviewapp.repository;

import android.app.Application;
import androidx.lifecycle.LiveData;
import com.example.bookreviewapp.api.BookApi;
import com.example.bookreviewapp.api.RetrofitClient;
import com.example.bookreviewapp.db.BookDao;
import com.example.bookreviewapp.db.BookDatabase;
import com.example.bookreviewapp.db.BookEntity;
import com.example.bookreviewapp.model.Book;
import java.util.List;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class BookRepository {
    private final BookApi api;
    private final BookDao dao;
    private final LiveData<List<BookEntity>> allBooks;

    public BookRepository(Application app) {
        api = RetrofitClient.getRetrofitInstance().create(BookApi.class);
        dao = BookDatabase.getInstance(app).bookDao();
        allBooks = dao.getAllBooks();
    }

    public LiveData<List<BookEntity>> getAllBooks() {
        return allBooks;
    }

    public void insert(BookEntity book) {
        BookDatabase.databaseWriteExecutor.execute(() -> dao.insert(book));
    }

    public void fetchBooks(Callback<List<Book>> callback) {
        api.getBooks().enqueue(callback);
    }
}
