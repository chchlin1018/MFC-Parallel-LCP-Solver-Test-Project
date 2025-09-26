


## ⚠️ 重要：設定大型依賴項目 (OpenUSD)

為了保持此 GitHub 儲存庫的輕量化，大型的第三方函式庫 **OpenUSD** 並未包含在版本控制中。您需要手動下載並將其放置到正確的位置才能成功編譯專案。

**步驟：**

1.  **下載 OpenUSD**：
    *   請從 [NVIDIA OpenUSD 下載頁面](https://developer.nvidia.com/usd) 下載適用於 Windows 的預編譯函式庫。
    *   請確保下載的版本與專案設定相符 (建議使用 25.05 或更高版本)。

2.  **解壓縮並放置**：
    *   解壓縮您下載的 ZIP 檔案。
    *   將解壓縮後的所有內容複製到以下目錄：
        ```
        /PhysicsSimMFC/vendor/openusd/
        ```
    *   完成後，您的 `openusd` 目錄結構應該如下所示：
        ```
        PhysicsSimMFC/
        └── vendor/
            └── openusd/
                ├── bin/
                ├── include/
                ├── lib/
                ├── ... (其他檔案和目錄)
        ```

完成以上步驟後，您就可以正常開啟 Visual Studio 解決方案並進行編譯了。

