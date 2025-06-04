
# Multi-threaded Web Server in C++

## Description
This project is a simple multi-threaded HTTP web server built using C++. It listens for coming client connections, hannddles multiple requests concurrently using a thread-pool, and serves static files such as HTML pages from a designated directory.

### Features
- **Multi-threading**: Handles multiple concurrent connections using a thread pool.
- **Socket Programming**: Uses POSIX sockets to listen for HTTP requests and respond.
- **Static File Serving**: Serves static files like HTML and images from the `www/` directory.
- **Basic HTTP Parsing**: Supports basic HTTP `GET` requests.

## Project Structure
```
/MultiThreadedWebServer
├── server.cpp      # Main server code
├── threadpool.cpp  # Implementation of thread pool
├── threadpool.h    # Header file for thread pool
├── utils.cpp       # Utility functions (e.g., request parsing)
├── utils.h         # Header file for utility functions
└── www/            # Directory containing static files (HTML, CSS, etc. (HTML onlyfor now :) )
```

## Setup & Compilation

### Prerequisites
- A Unix-like operating system (Linux or macOS). The code uses POSIX APIs, so it will require adjustments to run on Windows.
- `g++` or `clang++` compiler with C++11 or later support.
- Basic understanding of C++ threading, file handling, and socket programming.

### Steps

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/MultiThreadedWebServer.git
   cd MultiThreadedWebServer
   ```

2. **Compile the Code**:
   Use the `g++` compiler to compile the project:
   ```bash
   g++ server.cpp threadpool.cpp utils.cpp -o webserver -lpthread
   ```

3. **Run the Server**:
   ```bash
   ./webserver
   ```

4. **Access the Server**:
   Open your browser and visit `http://localhost:8080`. The default page served will be `index.html` from the `www/` folder.

## Thread Pool Implementation
The server implements a simple thread pool to manage concurrent client connections efficiently. The `ThreadPool` class creates a fixed number of threads that wait for tasks. As new client requests come in, they are added to a queue, and worker threads handle them as they become available.

## HTTP Request Handling
The server supports only `GET` requests. When a request is received, the server:
1. Parses the request to extract the file path.
2. Serves the corresponding file from the `www/` directory.
3. Returns a 404 error if the file is not found.

## Example
1. Place a file named `index.html` in the `www/` directory.
2. Run the server.
3. Open a browser and visit `http://localhost:8080` to see the content of `index.html`.

## Customizing the Server
You can customize the server by:
- Adding more advanced HTTP parsing to support other methods (e.g., `POST`, `PUT`).
- Adding more detailed error handling and logging.
- Expanding the file handling to support MIME types other than HTML.

## Testing
You can use a load testing tool such as Apache Benchmark (`ab`) to test the server's performance under different levels of concurrency:
```bash
ab -n 100 -c 10 http://localhost:8080/
```

## Contributing
Feel free to fork this repository, submit issues, and make pull requests. Contributions are welcome!

## License
This project is licensed under the MIT License.
