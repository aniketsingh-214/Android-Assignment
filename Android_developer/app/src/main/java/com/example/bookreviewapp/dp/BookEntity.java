package com.example.bookreviewapp.db;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "books")
public class BookEntity {
    @PrimaryKey
    public int id;
    public String title;
    public String author;
    public String description;
    public double rating;
    public String image;
}