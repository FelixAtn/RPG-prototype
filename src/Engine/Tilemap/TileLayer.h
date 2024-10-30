#pragma once

class TileLayer
{
public:
	TileLayer(const std::string& texture, const std::string& mapName, RenderingSystem& renderingManager);
	~TileLayer();
	void Init();
	void Update(float deltaTime);
	const std::vector<std::unique_ptr<Tile>>& GetTiles() { return m_Tiles; }

private:
	bool IsLoaded(const std::string& texture, const std::string& mapName);
	bool IsMapNameValid(const YAML::Node& mapData, const std::string& mapName);

private:
	std::vector<std::unique_ptr<Tile>> m_Tiles;
	std::vector<std::vector<int>> m_MatrixMap;
	RenderingSystem& m_RenderSystem;
};

