/*
Sample code for vulnerable type: Dereference of a NULL Pointer
CWE : CWE-476
Description : A pointer is assigned the return value of a standard library function that may return NULL and is not checked before use. NULL pointer use can lead to program crashes.
*/

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    fwrite(contents, 1, total_size, (FILE *)userp);
    return total_size;
}

int main() {
    CURL *curl;
    CURLcode res;

    char url[200];
    printf("Enter a URL to fetch: ");
    fgets(url, sizeof(url), stdin); 

    // Remove newline character from the URL
    char *newline = strchr(url, '\n');//source
    if (newline) {//sink
        *newline = '\0';
    }

    FILE *output = fopen("output.html", "wb");

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, output);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        fclose(output);
    } else {
        fclose(output);
    }

    return 0;
}

