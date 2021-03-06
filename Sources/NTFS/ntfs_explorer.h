#pragma once

#include <WinSock2.h>
#include <Windows.h>

#include "ntfs_explorer.h"
#include "ntfs_index_entry.h"
#include "ntfs_mft.h"
#include "ntfs_mft_record.h"
#include "ntfs.h"
#include "ntfs_reader.h"

#include <memory>
#include <vector>

class NTFSExplorer
{
private:
	std::wstring _volume_name;

	std::shared_ptr<MFT> _MFT;

	std::shared_ptr<NTFSReader> _reader;

public:
	explicit NTFSExplorer(std::wstring volume_name);
	~NTFSExplorer();

	std::wstring volume_name() const { return _volume_name; }

	std::shared_ptr<MFT> mft() { return _MFT; }

	std::shared_ptr<NTFSReader> reader() { return _reader; }

	std::vector<std::wstring> list(std::wstring directory);
};