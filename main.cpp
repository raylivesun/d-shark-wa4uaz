#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace std;

void encrypt(uint8_t* data, size_t size, uint8_t key) {
	for (size_t i = 0; i < size; i++) {
        data[i] ^= key;
    }
}

int main() {
	const char* input_file_path = "input.txt";
    const char* output_file_path = "output.txt";
    const uint8_t key = 0x12;

    FILE* input_file = fopen(input_file_path, "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", input_file_path);
        return 1;
    }

    FILE* output_file = fopen(output_file_path, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output file: %s\n", output_file_path);
        fclose(input_file);
        return 1;
    }

    uint8_t buffer[4096];
    size_t bytes_read;
	size_t total_bytes_written = 0;
	size_t total_bytes_read = 0;
	size_t bytes_to_encrypt;
	size_t bytes_encrypted = 0;
	size_t bytes_to_write;
	size_t bytes_written;
	size_t bytes_to_read_next_values = 4096;
	size_t bytes_remaining_in_current_values = 4096;
	size_t bytes_to_encrypt_in_current_values = 4096;
	size_t bytes_encrypted_in_current_values = 0;
	size_t bytes_to_write_in_current_values = 4096;
	size_t bytes_written_in_current_values = 0;
	uint8_t* current_values_buffer = buffer;
	uint8_t* current_values_encrypted_buffer = buffer;
	bool is_last_values = false;
	bool is_last_byte_encrypted = false;
	bool is_last_byte_written = false;
	bool is_first_values = true;
	bool is_first_byte_encrypted = true;
	bool is_first_byte_written = true;
	bool is_encrypted_byte_written = false;
	bool is_encrypted_byte_read = false;
	bool is_written_byte_read = false;
	bool is_written_byte_written = false;
	bool is_encrypted_byte_read_next_values = false;
	bool is_encrypted_byte_written_next_values = false;
	bool is_written_byte_read_next_values = false;
	bool is_written_byte_written_next_values = false;
	bool is_last_encrypted_byte_read = false;
	bool is_last_encrypted_byte_written = false;
	bool is_last_written_byte_read = false;
	bool is_last_written_byte_written = false;
	bool is_encrypted_byte_read_in_current_values = false;
	bool is_encrypted_byte_written_in_current_values = false;
	bool is_written_byte_read_in_current_values = false;
	bool is_written_byte_written_in_current_values = false;
	uint8_t current_encrypted_byte;
	uint8_t current_written_byte;
	uint8_t current_read_byte;
	uint8_t current_write_byte;
	uint8_t current_encrypted_byte_in_current_values;
	uint8_t current_written_byte_in_current_values;
	uint8_t current_read_byte_in_current_values;
	uint8_t current_write_byte_in_current_values;
	uint8_t current_encrypted_byte_next_values;
	uint8_t current_written_byte_next_values;
	uint8_t current_read_byte_next_values;
	uint8_t current_write_byte_next_values;
	uint8_t current_encrypted_byte_in_current_values_next_values;
	uint8_t current_written_byte_in_current_values_next_values;
	uint8_t current_read_byte_in_current_values_next_values;
	uint8_t current_write_byte_in_current_values_next_values;
	uint8_t current_encrypted_byte_last_values;
	uint8_t current_written_byte_last_values;
	uint8_t current_read_byte_last_values;
	uint8_t current_write_byte_last_values;
	uint8_t current_encrypted_byte_last_values_next_values;
	uint8_t current_written_byte_last_values_next_values;
	uint8_t current_read_byte_last_values_next_values;
	uint8_t current_write_byte_last_values_next_values;
	uint8_t current_encrypted_byte_encrypted_byte_last_values;
	uint8_t current_written_byte_encrypted_byte_last_values;
	uint8_t current_read_byte_encrypted_byte_last_values;
	uint8_t current_write_byte_encrypted_byte_last_values;
	uint8_t current_encrypted_byte_encrypted_byte_last_values_next_values;
	uint8_t current_written_byte_encrypted_byte_last_values_next_values;
	uint8_t current_read_byte_encrypted_byte_last_values_next_values;
	uint8_t current_write_byte_encrypted_byte_last_values_next_values;
	uint8_t current_encrypted_byte_last_encrypted_byte_last_values;
	uint8_t current_written_byte_last_encrypted_byte_last_values;
	uint8_t current_read_byte_last_encrypted_byte_last_values;
	uint8_t current_write_byte_last_encrypted_byte_last_values;
	uint8_t current_encrypted_byte_last_encrypted_byte_last_values_next_values;
	uint8_t current_written_byte_last_encrypted_byte_last_values_next_values;
	uint8_t current_read_byte_last_encrypted_byte_last_values_next_values;
	uint8_t current_write_byte_last_encrypted_byte_last_values_next_values;

		while ((bytes_read = fread(buffer, 1, bytes_to_read_next_values, input_file)) > 0) {
			bytes_remaining_in_current_values -= bytes_read;
            total_bytes_read += bytes_read;
            bytes_to_encrypt_in_current_values -= bytes_read;
            bytes_encrypted_in_current_values += bytes_read;
            bytes_to_write_in_current_values += bytes_read;
            bytes_written_in_current_values += bytes_read;
		}
		is_last_values = (bytes_remaining_in_current_values == 0);
		is_last_byte_encrypted = (bytes_encrypted_in_current_values == 0);
		is_last_byte_written = (bytes_written_in_current_values == 0);
		is_encrypted_byte_read_next_values = (bytes_remaining_in_current_values == 0 &&!is_last_values);
		is_encrypted_byte_written_next_values = (bytes_encrypted_in_current_values == 0 &&!is_last_values);
		is_written_byte_read_next_values = (bytes_remaining_in_current_values == 0 &&!is_last_values);
		is_written_byte_written_next_values = (bytes_written_in_current_values == 0 &&!is_last_values);
		is_last_encrypted_byte_read = (bytes_encrypted_in_current_values == 0 && is_last_values);
		is_last_encrypted_byte_written = (bytes_written_in_current_values == 0 && is_last_values);
		is_last_written_byte_read = (bytes_remaining_in_current_values == 0 && is_last_values);
		is_last_written_byte_written = (bytes_written_in_current_values == 0 && is_last_values);
		is_encrypted_byte_read_in_current_values = (bytes_encrypted_in_current_values > 0);
		is_encrypted_byte_written_in_current_values = (bytes_encrypted_in_current_values > 0);
		is_written_byte_read_in_current_values = (bytes_remaining_in_current_values > 0);
		is_written_byte_written_in_current_values = (bytes_written_in_current_values > 0);
		current_values_buffer = buffer;
		current_values_encrypted_buffer = buffer;
		current_encrypted_byte_in_current_values = *current_values_buffer;
		current_written_byte_in_current_values = *current_values_buffer;
		current_read_byte_in_current_values = *current_values_buffer;
		current_write_byte_in_current_values = *current_values_buffer;
		current_encrypted_byte_next_values = *current_values_buffer;
		current_written_byte_next_values = *current_values_buffer;
		current_read_byte_next_values = *current_values_buffer;
		current_write_byte_next_values = *current_values_buffer;
		current_encrypted_byte_in_current_values_next_values = *current_values_buffer;
		current_written_byte_in_current_values_next_values = *current_values_buffer;
		current_read_byte_in_current_values_next_values = *current_values_buffer;
		current_write_byte_in_current_values_next_values = *current_values_buffer;
		current_encrypted_byte_last_values = *current_values_buffer;
		current_written_byte_last_values = *current_values_buffer;
		current_read_byte_last_values = *current_values_buffer;
		current_write_byte_last_values = *current_values_buffer;
		current_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_written_byte_last_values_next_values = *current_values_buffer;
		current_read_byte_last_values_next_values = *current_values_buffer;
		current_write_byte_last_values_next_values = *current_values_buffer;
		current_encrypted_byte_encrypted_byte_last_values = *current_values_buffer;
		current_written_byte_encrypted_byte_last_values = *current_values_buffer;
		current_read_byte_encrypted_byte_last_values = *current_values_buffer;
		current_write_byte_encrypted_byte_last_values = *current_values_buffer;
		current_encrypted_byte_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_written_byte_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_read_byte_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_write_byte_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_encrypted_byte_last_encrypted_byte_last_values = *current_values_buffer;
		current_written_byte_last_encrypted_byte_last_values = *current_values_buffer;
		current_read_byte_last_encrypted_byte_last_values = *current_values_buffer;
		current_write_byte_last_encrypted_byte_last_values = *current_values_buffer;
		current_encrypted_byte_last_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_written_byte_last_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_read_byte_last_encrypted_byte_last_values_next_values = *current_values_buffer;
		current_write_byte_last_encrypted_byte_last_values_next_values = *current_values_buffer;
}

