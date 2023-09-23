## Password Generator

A secure passphrase generator that uses a domain and a base keyphrase to produce a unique, hashed passphrase for each site or application. This project harnesses the power of `BLAKE2` via `libsodium` and `SHA3` via `OpenSSL` for hashing, and employs `wxWidgets` for its GUI.

### Features

- **User-friendly GUI**: Powered by `wxWidgets`.
- **Dual Hashing**: Utilizes both `BLAKE2` (from `libsodium`) and `SHA3` (from `OpenSSL`) to ensure a robust hashing mechanism.
- **Easy to Use**: Just input the domain and your base keyphrase, then get a secure, reproducible passphrase.

### Prerequisites

- `wxWidgets`
- `libsodium`
- `OpenSSL`

### Building

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/ahmadhaileh/generator-sha3-blake2.git
    cd generator-sha3-blake2
    ```

2. **Configure with CMake**:
    ```bash
    mkdir build
    cd build
    cmake ..
    ```

3. **Build the Project**:
    ```bash
    cmake --build .
    ```

### Usage

Run the compiled executable. Input your domain (e.g., `example.com`) and your base keyphrase into the GUI. Click the "Generate" button to get your hashed passphrase.

### Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

### License

[MIT](https://choosealicense.com/licenses/mit/)
