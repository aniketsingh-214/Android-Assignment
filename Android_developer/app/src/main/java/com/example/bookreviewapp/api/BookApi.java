package com.example.bookreviewapp.api;

import com.example.bookreviewapp.model.Book;
import java.util.List;
import retrofit2.Call;
import retrofit2.http.GET;

public interface BookApi {
    @GET("books.json")
    Call<List<Book>> getBooks();
}
