package com.example.bookreviewapp.viewmodel;

import android.app.Application;
import androidx.annotation.NonNull;
import androidx.lifecycle.AndroidViewModel;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import com.example.bookreviewapp.db.BookEntity;
import com.example.bookreviewapp.model.Book;
import com.example.bookreviewapp.repository.BookRepository;
import java.util.List;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;

public class BookViewModel extends AndroidViewModel {
    private final BookRepository repo;
    private final MutableLiveData<List<Book>> booksFromApi = new MutableLiveData<>();

    public BookViewModel(@NonNull Application app) {
        super(app);
        repo = new BookRepository(app);
    }

    public LiveData<List<Book>> getBooksFromApi() {
        return booksFromApi;
    }

    public LiveData<List<BookEntity>> getSavedBooks() {
        return repo.getAllBooks();
    }

    public void fetchBooks() {
        repo.fetchBooks(new Callback<List<Book>>() {
            @Override
            public void onResponse(Call<List<Book>> call, Response<List<Book>> response) {
                if (response.isSuccessful()) {
                    booksFromApi.setValue(response.body());
                }
            }

            @Override
            public void onFailure(Call<List<Book>> call, Throwable t) {
                booksFromApi.setValue(null);
            }
        });
    }

    public void saveBook(BookEntity book) {
        repo.insert(book);
    }
}
