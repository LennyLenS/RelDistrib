from database import generate_author, generate_book, generate_genres, generate_subscriber, generate_subscription
import random


def author_insertion(number):

    file_name = "authors.txt"

    with open(file_name, "w") as file:
        file.write(str(number) + " 2\n")
        file.write("id a_name\n")
        file.write("int char(256)\n")

        id_seq = 0
        for _ in range(number):
            name = generate_author()
            id_seq += 1
            
            file.write(str(id_seq) + " " + name + "\n")
        
    print(f"Generate {number} records about the authors!")

def books_insertion(number):

    file_name = "books.txt"

    with open(file_name, "w") as file:
        file.write(str(number) + " 4\n")
        file.write("id b_name b_year b_quantity\n")
        file.write("int char(256) int int\n")

        id_seq = 0
        for _ in range(number):
            name, year, quantity = generate_book()
            id_seq += 1
            
            file.write(str(id_seq) + " " + name + " " + str(year) + " " + str(quantity) +"\n")
        
    print(f"Generate {number} records about the books!")


def genres_insertion(connection):
    table_name = f"\"library\".genres"
    cur = connection.cursor()
    
    values = ""

    result = generate_genres()
    values += f" VALUES (\'{result[0]}\')"

    for i in range(1, 100):
        values += f", (\'{result[i]}\')"
        
    cur.execute(
        f"INSERT INTO {table_name} (g_name) "
        + values
    )

    connection.commit() 
    print("Users were added successfully!")

def subscribers_insertion(connection, number):
    table_name = f"\"library\".subscribers"
    cur = connection.cursor()
    
    values = ""

    name = generate_subscriber()
    values += f" VALUES (\'{name}\')"

    for _ in range(number - 1):
        name = generate_subscriber()
        values += f", (\'{name}\')"
        
    cur.execute(
        f"INSERT INTO {table_name} (s_name) "
        + values
    )

    connection.commit()
    print("Users were added successfully!")

def books_author_insertion():

    file_name_read1 = "authors.txt"
    file_name_read2 = "books.txt"
    file_name_write = "books_authors.txt"

    authors = []
    with open(file_name_read1, "r") as file:
        n = int(file.readline().split()[0])
        file.readline()
        file.readline()
        for line in file:
            authors.append(line.split()[0])

    books = []
    with open(file_name_read1, "r") as file:
        n = int(file.readline().split()[0])
        file.readline()
        file.readline()
        for line in file:
            books.append(line.split()[0])

    random_dig = []
    for _ in books:
        random_dig.append(random.randint(1, 4))
    number = sum(random_dig)

    with open(file_name_write, "w") as file:
        file.write(str(number) + " 2\n")
        file.write("b_id a_id\n")
        file.write("int int\n")

        for i in range(len(books)):
            author_sample = random.sample(authors, random_dig[i])

            for j in range(random_dig[i]):
                file.write(books[i] + " " + author_sample[j] + "\n")
        
    print(f"Generate {number} records about the authors!")

def books_genres_insertion(connection):
    cur = connection.cursor() 
    
    cur.execute(
        f"SELECT b_id FROM \"library\".books;"
    )
    all_b_id = list(cur.fetchall())
    
    
    cur.execute(
        f"SELECT g_id FROM \"library\".genres"
    )
    all_g_id = list(cur.fetchall())
    
    table_name = f"\"library\".m2m_books_genres"
    values = ""

    author_sample = random.sample(all_g_id, 10)
    values += f" VALUES ({all_b_id[0][0]}, {author_sample[0][0]})"

    for i in range(1, 10):
        values += f", ({all_b_id[0][0]}, {author_sample[i][0]})"


    for j in range(1, len(all_b_id)):
        author_sample = random.sample(all_g_id, 10)

        for i in range(10):
            values += f", ({all_b_id[j][0]}, {author_sample[i][0]})"
            
    cur.execute(
        f"INSERT INTO {table_name} (b_id, g_id) "
        + values
    )

    connection.commit()
    print("User_desks were added successfully!")

def subscriptions_insertion(connection):
    cur = connection.cursor() 
    
    cur.execute(
        f"SELECT b_id FROM \"library\".books;"
    )
    all_b_id = list(cur.fetchall())
    
    
    cur.execute(
        f"SELECT s_id FROM \"library\".subscribers"
    )
    all_s_id = list(cur.fetchall())
    
    table_name = f"\"library\".subscriptions"
    values = ""

    result = generate_subscription()
    book_sample = random.sample(all_b_id, 10)
    values += f" VALUES ({all_s_id[0][0]}, {book_sample[0][0]}, to_date(\'{result[0]}\', \'DD-MON-RR\'), to_date(\'{result[1]}\', \'DD-MON-RR\'), \'{result[2]}\')"

    for i in range(1, 10):
        result = generate_subscription()
        values += f", ({all_s_id[0][0]}, {book_sample[i][0]}, to_date(\'{result[0]}\', \'DD-MON-RR\'), to_date(\'{result[1]}\', \'DD-MON-RR\'), \'{result[2]}\')"


    for j in range(1, len(all_s_id)):
        book_sample = random.sample(all_b_id, 10)

        for i in range(10):
            result = generate_subscription()
            values = f"VALUES ({all_s_id[j][0]}, {book_sample[i][0]}, to_date(\'{result[0]}\', \'DD-MON-RR\'), to_date(\'{result[1]}\', \'DD-MON-RR\'), \'{result[2]}\')"
            
    cur.execute(
        f"INSERT INTO {table_name} (sb_subscriber, sb_book, sb_start, sb_finish, sb_is_active) "
        + values
    )

    connection.commit()
    print("User_desks were added successfully!")